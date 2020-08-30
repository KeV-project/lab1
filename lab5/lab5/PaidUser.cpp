#include "PaidUser.h"

void PaidUser::SetPosts(Post* posts, const int postsCount)
{
	if (postsCount < 0)
	{
		string message = "Число " + to_string(postsCount) 
			+ " не может определять количество постов" 
			+ "\nтак как не является положительным";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	_posts = posts;
	_postsCount = postsCount;
}


Post* PaidUser::GetPosts() 
{
	return _posts; 
}
int PaidUser::GetPostsCount()
{ 
	return _postsCount;
}

PaidUser::PaidUser() : User()
{
	SetPosts(nullptr, 0);
}

PaidUser::PaidUser(const int id, const string& login, 
	const string& password) : User(id, login, password)
{
	SetPosts(nullptr, 0);
}

PaidUser::PaidUser(const int id, const string& login, 
	const string& password, Post* posts, const int postsCount) : 
	User(id, login, password)
{
	SetPosts(posts, postsCount);
}
