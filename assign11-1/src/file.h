
#ifndef FILE_H_
#define FILE_H_

class file
{
		int roll;
	    char name[50];
		char subject[20];
		long int code;
		float internal;
	  	float marks;
	  public:
	  	  void create();
	  	  void insert(int);
	  	  void search(char str[]);
	  	  void edit(char str[]);
	  	  void delete1(char str[]);
	  	  void display();
	  	  void display_file();
};

#endif /* FILE_H_ */
