#include "Application.h"

#undef main

void PathfinderTest()
{
	// Initialise pathfinder
	int levelWidth = 20, levelHeight = 10;
	Pathfinder p{ levelWidth,levelHeight };
	p.m_canTraverseDiagonally = false;
	// Create a wall (for testing)
	for (size_t i = 0; i < levelWidth - 1; i++)
		p.SetNodeIsTraversible(Vector2{ (float)i, 2.5f }, false);

	// Search for path
	vector<Vector2> path = p.FindPath({ 0.5f, 0.5f }, { 1.5f, 9.3f });
	p.PrintNodeMatrix(path);

	// Output path coordinates list
	/*for (size_t i = 0; i < path.size(); i++)
		cout << '(' << path[i].x << ',' << path[i].y << '), ';*/
	//cout << endl;
}

int main(void) 
{
	PathfinderTest();

	Application* app = new Application();

	if (app->initApp())
	{
		app->loopApp();
	}

	delete app;
	app = nullptr;

	return 0;

}