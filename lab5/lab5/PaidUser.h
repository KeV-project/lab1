#pragma once
#include "Post.h"
#include "User.h"

class PaidUser : public User
{
private:
	int _postsCount;
	Post* _posts;

public:
	void SetPosts(Post* posts, const int postsCount);

	Post* GetPosts();
	int GetPostsCount();

	PaidUser();
	PaidUser(const int id, const string& login,
		const string& password);
	PaidUser(const int id, const string& login, 
		const string& password, Post* posts, const int postsCount);
};


