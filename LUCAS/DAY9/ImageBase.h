#pragma once
class ImageBase
{
public:
	ImageBase();
	~ImageBase();
	ImageBase(const ImageBase& other);
	int w = 10;
	int h = 10;
	int depth = 1 ;
	void virtual run();
	void virtual forcerun() = 0;
};

