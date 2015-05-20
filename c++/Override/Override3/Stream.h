#ifndef STREAM_H_
#define STREAM_H_

class Stream{
public:
	double Get() const;
	bool Set();

protected:
	virtual void SetBase();
	double m_n;
};

#endif