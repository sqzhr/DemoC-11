#pragma once
class Carry
{
private: 
	int n; 
	char *pc; 
	static int ct;
	void ShowObject() const;
public:
	Carry();
	explicit Carry(int k);
	Carry(int k, char ch);
	Carry(const Carry &f);
	Carry(Carry &&f);
	~Carry();
	Carry operator+ (const Carry &f) const;
	void ShowData() const;
};

