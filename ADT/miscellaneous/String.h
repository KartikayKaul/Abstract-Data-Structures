#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class String
{
	/*
	
		My own implementation of String type
		The inernal data structure of string makes use of std::vector
		and its operations

		you can access and change the internal element of the string using subscript [] operator
	*/
	vector<char> feed;
	long _size;
	
	public:
	String() {
		this->_size = this->feed.size();
	}

	String(long _size) {
		this->_size = _size;
		this->feed.reserve(this->_size);
	}

	String(vector<char> feed) {
		this->feed = feed;
		this->_size = this->feed.size();
	}
	//operations

	String(const char* str) {
		long len = strlen(str);
		feed.reserve(len);
		for(auto *i=str; *i!='\0'; i++)
			this->feed.push_back(*i);
		this->_size = len;
	}

	String(const String &s) {
		this->feed = s.feed;
		this->_size = this->feed.size();
	}

	// display values
	void display() {
		for(auto i=this->feed.begin(); i!=this->feed.end(); ++i)
			cout<<*i;
	}

	long size(){return this->_size;}

	//concatenate two strings
	String operator+(String s1);
	String operator+(char c);

	//append methods
	void append(String s) {
		this->feed.insert(this->feed.end(), s.feed.begin(), s.feed.end());
		this->_size = this->feed.size();
	}
	void append(char s) {
		this->feed.push_back(s);
		this->_size = this->feed.size();
	}


	// some operations
	String capitalize();
	String upper();
	String lower();
	bool startsWith(char val);
	bool endsWith(char val);
	vector<String> split(char separator);
	String strip();
	String cipher(int, int);
	String decipher(int, int);

	// operator overloads below
	friend ostream& operator<<(ostream& os, String s) {
		for(long i=0; i<s.size(); i++)
			os<<s.feed[i];

		return os;
	}

	String operator*(int times);

	char& operator[](long idx) {
		if(idx >= 0 && idx < this->size())
			return this->feed[idx];
		else if(idx >= -this->size() && idx <= -1 )
			return this->feed[this->size() + idx];
		else
			throw std::invalid_argument("Index value out of range.");
	}

	bool operator==(String s) {
		if(this->feed == s.feed)
			return true;
		return false;
	}
	
	//assignment overload
	void operator=(const String &);

	//String slicing
	String operator()(long,long);
};


// Function definitions for some methods
String String::cipher(int cipherstep, int stride=1){
	/*
		Input
			cipherstep : an integer step by which the cipher moves
			stride : stride over the string
		Output
			A cipher String
	*/

	String cipher_ = *this;
	cipherstep = cipherstep % 26;
	for(long i=0; i<this->size(); i+=stride) {
		if( (cipher_[i] >= 'A' && cipher_[i] <= 'Z') || ( cipher_[i] >= 'a' && cipher_[i] <= 'z')  ) {
			if(cipher_[i] >= 'A' && cipher_[i] <= 'Z')
				cipher_[i] = char(int(cipher_[i] + cipherstep - 65 + 26) % 26 + 65);   
			else
				cipher_[i] = char(int(cipher_[i] + cipherstep - 97 + 26) % 26 + 97);	
		}
	}

	return cipher_;
}

String String::decipher(int cipherstep, int stride=1) {
	/*
		Input
			key => (cipherstep, stride)
				cipherstep : an integer step to be reversed
				stride : stride over the string

				note: these are the values you used to produce the cipher string
		Output
			A deciphered String	
	*/

	String decipher_ = *this;
	cipherstep = cipherstep % 26;
	for(long i=0; i<this->size(); i+=stride) {
		if( (decipher_[i] >= 'A' && decipher_[i] <= 'Z') || ( decipher_[i] >= 'a' && decipher_[i] <= 'z')  ) {
			if(decipher_[i] >= 'A' && decipher_[i] <= 'Z')
				decipher_[i] = char((int(decipher_[i]) - cipherstep - 65 + 26) % 26 + 65);
			else
				decipher_[i] = char((int(decipher_[i]) - cipherstep - 97 + 26) % 26 + 97);
		}
	}
	return decipher_;
}

String String::operator*(int times) {
	String s="";
	for(int i=0; i<times; i++)
		s.append(*this);
	
	return s;
}

String String::operator()(long start, long end){
	String s = *this, toss;
	
	if(start >= end)
		throw std::invalid_argument("Start index greater than end index.");
	if(start >= 0 && end >= 0){
		if(start >= this->size() || end >= this->size() && s.size() != 1)
			throw std::invalid_argument("Index out of range.");
		else {
			for(long i=start; i<end; i++)
				toss.append(s[i]);

			return toss;
		}
	}
	else if(start < 0 && end < 0) {
		if(start < -this->size() || end < -this->size())
			throw std::invalid_argument("Index out of range.");
		else {
			for(long i=start; i<=end; i++)
				toss.append(s[i]);

			return toss;
		}
	}
	else 
		throw std::invalid_argument("Undetectable error in index values.");
}

String String::operator+(char c) {
	String s = *this;
	s.append(c);
	return s;
}

vector<String> String::split(char separator=' ') {
    /*
		Returns a vector of Strings
		Each element of the vector is a string separated by the `separator` char
		variable which is a whitespace by default

		The separator is not included within the elements of the vector returned
	*/
	vector<String> container;
	String stringy="";
	
	for(long i=0; i<this->size(); i++) {
		if(this->feed[i] == separator ) {
			container.push_back(stringy);
			stringy = "";
		} else if(i == this->size() - 1) {
			stringy = stringy + this->feed[i];
			container.push_back(stringy);
		}
		else stringy = stringy + this->feed[i];
	 }

	 return container;
}

String String::operator+(String s1) {
	//O(n) 
	// currently searching ways for efficient concatenation
	// if possible might change entire data structure for string
	// to accomodate for good concatenation
	String s;
	s.feed.insert(s.feed.end(), this->feed.begin(), this->feed.end());
	s.feed.insert(s.feed.end(), s1.feed.begin(), s1.feed.end());
	return s;
}

String String::capitalize() {
	String s = *this;
	if(s.feed[0] >= 'a' && s.feed[0] <='z')
		s.feed[0] = s.feed[0] - ('a' - 'A');
	return s;
}

String String::upper() {
	String s = *this;
	
	for(long i=0; i<s.size(); i++)
		if(s.feed[i] >= 'a' && s.feed[i] <='z')
			s.feed[i] = s.feed[i] - ('a' - 'A');
	return s;
}

String String::lower() {
	String s = *this;
	for(long i=0; i<s.size(); i++)
		if(s.feed[i] >= 'A' && s.feed[i] <= 'Z')
			s.feed[i] = s.feed[i] + ('a' - 'A');
	return s;
}

bool String::startsWith(char val) {
	if(this->feed[0] == val)
		return true;
	return false;
}

bool String::endsWith(char val) {
	long final_index = this->size() - 1;
	if(this->feed[final_index] == val)
		return true;
	return false;
}

void String::operator=(const String &s1) {
	this->feed = s1.feed;
	this->_size = s1._size;
}