#include "PaidUser.h"

void PaidUser::SetPosts(Post* posts, const int postsCount)
{
	const int minPostsCount = 0;
	const int maxPostsCount = 10;
	ValueValidator::AssertValueInRange(postsCount, 
		minPostsCount, maxPostsCount, NotInRange,
		"количество постов пользователя");
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
