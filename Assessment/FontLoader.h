#pragma once
#include <string.h>
#include <string>

using namespace std;

class FontLoader 
{
public:
	void loadFontFromFile(string filename);

	Font getFontForText(Text text);

	FontLoader(string filename);
private:
	std::unordered_map<std::string, const Font*> m_Fonts;
};



Constructor(Filepath, Renderer, size, color)
Update Text(string)
Change pos(x, y)
CreateFontTexture()
GetRect()
GetTexture()