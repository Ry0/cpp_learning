#ifndef STREAM_H_
#define STREAM_H_

class Stream{
public:
	double Get() const;
	bool Set();

protected:
	double m_n;
};

#endif