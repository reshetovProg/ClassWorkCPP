#pragma once
class Cookie {
public:
	void virtual info()=0;
};

class ChocCookie : public Cookie {
public:
	void info() {
	std::cout << " create chocolate Cookie" << std::endl;
	}
};

class CocosCookie : public Cookie {
public:
	void info() {
		std::cout << " create cocos Cookie" << std::endl;
	}
};

class Factory {
public:
	virtual Cookie* createCookie() = 0;
};

class ChocCookieFactory: public Factory {
public:
	Cookie* createCookie() {
		return new ChocCookie;
	}
};

class CocosCookieFactory : public Factory {
public:
	Cookie* createCookie() {
		return new CocosCookie;
	}
};
