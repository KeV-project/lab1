#include "Post.h"

void Post::SetTitle(const string& title)
{
	_title = title;
}
void Post::SetText(const string& text)
{
	_text = text;
}

string Post::GetTitle() 
{ 
	return _title; 

}

string Post::GetText() 
{
	return _text; 
}

Post::Post(const string& title, const string& text)
{
	SetTitle(title);
	SetText(text);
}

