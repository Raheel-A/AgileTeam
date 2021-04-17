#include <iostream>
#include <vector>
#include <algorithm>

#include "Vector2.h"
#include "Vector2Int.h"
#include "LevelNode.h"
#include "Pathfinder.h"

using namespace std;

const float MOVE_COST_CARD = 1.0f;
const float MOVE_COST_DIAG = 1.414f;


Pathfinder::Pathfinder(int width, int height) : m_width(width), m_height(height)
{
    m_nodes = new LevelNode * [m_width * m_height];
    for (int i = 0; i < m_width * m_height; i++)
    {
        m_nodes[i] = new LevelNode{ true, GetReveseIndex(i) };
        LevelNode* n = m_nodes[i];
    }
}

Pathfinder::~Pathfinder()
{
    delete[] m_nodes;
}

std::vector<Vector2> Pathfinder::FindPath(Vector2 from, Vector2 to)
{
    //====Setup====
    //TODO out of range validity check

    // Store pointers to start and target nodes
    Vector2Int startPos{ from };
    Vector2Int targetPos{ to };
    LevelNode* startNode = IndexNodes(startPos);
    LevelNode* targetNode = IndexNodes(targetPos);

    vector<LevelNode*> openList;
    vector<LevelNode*> closedList;
    vector<LevelNode*> nodePath;

    LevelNode* currentNode = startNode;

    if (startNode == targetNode) return std::vector<Vector2>();

    openList.push_back(currentNode);


    //====Search====
    while (currentNode != targetNode)
    {
        closedList.push_back(currentNode);
        openList.erase(find(openList.begin(), openList.end(), currentNode));

        for (int y = -1; y <= 1; y++)
        {
            for (int x = -1; x <= 1; x++)
            {
                // Skip diagonals
                if (m_canTraverseDiagonally == false)
                    if (abs(x) == abs(y)) continue;
                // Skip currentNode
                if (x == 0 && y == 0) continue;
                // Store position to current adjacent tile being checked
                Vector2Int adjacentWorldPos{ currentNode->pos.x + x, currentNode->pos.y + y };
                // Skip out of bounds positions
                if (IsInBounds(adjacentWorldPos) == false) continue;
                // Store pointer to found adjacent node
                LevelNode* adjacentNode = IndexNodes(adjacentWorldPos);
                // Skip non-traversible tiles
                if (adjacentNode->isTraversible == false) continue;
                // Skip already checked nodes
                if (std::find(closedList.begin(), closedList.end(), adjacentNode) != closedList.end()) continue;
                // Walk around corners - prevent cutting into non-traversible nodes diagonally
                if (abs(x) == abs(y))
                {
                    if (IsInBounds({ adjacentWorldPos.x - x, adjacentWorldPos.y }))
                        if (IndexNodes(adjacentWorldPos.x - x, adjacentWorldPos.y)->isTraversible == false) continue;
                    if (IsInBounds({ adjacentWorldPos.x, adjacentWorldPos.y - 1 }))
                        if (IndexNodes(adjacentWorldPos.x, adjacentWorldPos.y - 1)->isTraversible == false) continue;
                }

                float movementCost = (abs(x) == abs(y)) ? MOVE_COST_DIAG : MOVE_COST_CARD;

                if (std::find(openList.begin(), openList.end(), adjacentNode) != openList.end())
                {
                    // Is the new path cheaper than the previously checked path
                    if (currentNode->g + movementCost < adjacentNode->g)
                    {
                        // Update node data
                        adjacentNode->parentNode = currentNode;
                        adjacentNode->g = currentNode->g + movementCost;
                        adjacentNode->f = adjacentNode->g + adjacentNode->h;
                    }
                }
                else
                {
                    // Update node with new data
                    adjacentNode->parentNode = currentNode;
                    adjacentNode->g = currentNode->g + movementCost;
                    adjacentNode->h = abs(targetNode->pos.x - adjacentWorldPos.x) + abs(targetNode->pos.y - adjacentWorldPos.y);
                    adjacentNode->f = adjacentNode->g + adjacentNode->h;
                    openList.push_back(adjacentNode);
                }

                // Check if end is reached
                if (adjacentNode == targetNode)
                {
                    closedList.push_back(adjacentNode);
                    currentNode = targetNode;
                }
            }
        }

        // Force out of the search if the target node has been found
        if (currentNode == targetNode) break;
        // Force out of the search if no more nodes available for checking
        if (openList.size() == 0) break;

        // Find cheapest node in open list
        LevelNode* cheapestNode = openList[0];
        for (size_t i = 1; i < openList.size(); i++)
        {
            if (openList[i]->f < cheapestNode->f)
                cheapestNode = openList[i];
        }
        currentNode = cheapestNode;
    }


    // Resolution
    nodePath = AddNodeToPath(currentNode, nodePath);
    if (nodePath.size() == 0) return vector<Vector2>();
    if (nodePath[0] != targetNode) return vector<Vector2>();

    // Crete path of Vector2s's in reverse order
    vector<Vector2> outPath;
    for (int i = nodePath.size() - 1; i >= 0; i--)
    {
        outPath.push_back({ Vector2{(float)nodePath[i]->pos.x, (float)nodePath[i]->pos.y } + Vector2{0.5f, 0.5f} });
    }

    // Clear node data for the next search
    for (size_t i = 0; i < openList.size(); i++)
        openList[i]->ResetCostData();
    for (size_t i = 0; i < closedList.size(); i++)
        closedList[i]->ResetCostData();

    return outPath;
}

void Pathfinder::SetNodeIsTraversible(Vector2 nodePos, bool v)
{
    SetNodeIsTraversible(Vector2Int{ nodePos }, v);
}

void Pathfinder::SetNodeIsTraversible(Vector2Int nodePos, bool v)
{
    IndexNodes(nodePos)->isTraversible = v;
}

void Pathfinder::PrintNodeMatrix(vector<Vector2> path)
{
    // Top Coords
    if (m_width < 11)
    {
        for (size_t i = 0; i < m_width; i++)
            cout << i;
        cout << endl;
    }

    // Top Line
    for (size_t i = 0; i < m_width + 1; i++)
        cout << (char)219;
    cout << endl;

    for (size_t y = 0; y < m_height; y++)
    {
        for (size_t x = 0; x < m_width; x++)
        {
            bool isPath = false;
            for (size_t i = 0; i < path.size(); i++)
            {
                if ((int)path[i].x == x && (int)path[i].y == y)
                    isPath = true;
            }

            // Print path character
            if (isPath) cout << (char)176;
            // Print node character
            else cout << (IndexNodes(x, y)->isTraversible ? ' ' : (char)219);
        }
        if (m_height < 11)
            cout << (char)219 << y << endl;
        else
            cout << (char)219 << endl;
    }

    // Bottom Line
    for (size_t i = 0; i < m_width + 1; i++)
    {
        cout << (char)219;
    }
    cout << endl;
}

LevelNode* Pathfinder::IndexNodes(int x, int y)
{
    return m_nodes[x + m_width * y];
}

LevelNode* Pathfinder::IndexNodes(Vector2Int v)
{
    return m_nodes[v.x + m_width * v.y];
}

int Pathfinder::GetIndex(int x, int y)
{
    return x + m_width * y;
}

Vector2Int Pathfinder::GetReveseIndex(int i)
{
    return Vector2Int(i % m_width, i / m_width);
}

bool Pathfinder::IsInBounds(Vector2Int v)
{
    return v.x < 0 || v.x > m_width - 1 || v.y < 0 || v.y > m_height - 1 ? false : true;
}

std::vector<LevelNode*>& Pathfinder::AddNodeToPath(LevelNode* n, std::vector<LevelNode*>& path)
{
    path.push_back(n);
    if (n->parentNode != nullptr)
        AddNodeToPath(n->parentNode, path);
    return path;
}
