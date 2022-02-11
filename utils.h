#ifndef UTILS_H
#define UTILS_H

#define pub
#define priv

#define class(name, empty, pubc, privc) \
	typedef struct name name;             \
	typedef struct name##Pr name##Pr;     \
	struct name                           \
	{                                     \
		pubc                                \
	};                                    \
	struct name##Pr                       \
	{                                     \
		name public;                        \
		privc                               \
	};

#define constructor(parent, ...)                                   \
	parent *parent##_new(__VA_ARGS__)                                \
	{                                                                \
		parent##Pr *_this = (parent##Pr *)malloc(sizeof(parent##Pr));  \
		parent *this __attribute__((unused)) = &_this->public;

#define destructor(parent)                                  \
	void parent##_delete(parent##Pr *_this)                   \
	{                                                         \
		parent *this __attribute__((unused)) = &_this->public;

#define method(parent, ...)                                 \
	(parent##Pr * _this, ##__VA_ARGS__)                       \
	{                                                         \
		parent *this __attribute__((unused)) = &_this->public;

#define init(this, ...)                      \
	*(this) = (typeof(*(this))){__VA_ARGS__};

#define endm }
#define endc      \
		return this;  \
	}
#define endd      \
		free(_this);  \
	}

#endif
