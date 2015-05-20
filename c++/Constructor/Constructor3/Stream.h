#ifndef STREAM_H_
#define STREAM_H_

class Stream{
public:
	Stream();
	double Get() const;
	bool Set();

protected:
	virtual void SetBase() = 0;
	double m_n;
};

#endif