#ifndef UTILS_H
#define UTILS_H

#define class(name, pub, priv) \
	typedef struct { pub } name ; \
	typedef struct { name public; priv } name ## Pr ;

#define constructor(parent, ...) \
	parent * parent ## _new (__VA_ARGS__) { \
		parent ## Pr *_this = (parent ## Pr *)malloc(sizeof(parent ## Pr)); \
		parent *this = &_this->public;

#define destructor(parent) \
	void parent ## _delete(parent ## Pr * _this) { \
		parent *this = &_this->public;

#define method(parent, ...) \
	(parent ## Pr *_this , ## __VA_ARGS__) { \
		parent *this = &_this->public;

#define init(this, ...) \
	(this) = malloc(sizeof(*(this))); \
	*(this) = (typeof(*(this))){ __VA_ARGS__ };

#define endm }
#define endc \
		return this; \
	}
#define endd \
		free(_this); \
	}

#endif
