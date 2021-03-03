#pragma once

using namespace std;

class FontLoader 
{
public:
	void loadFontFromFile(String filename);

	Font getFontForText(Text text);

	FontLoader();
private:
	std::unordered_map<std::string, const Font*> m_Fonts;
};