#pragma once
#include "IView.h"

 class ViewFactory
{
public:
	ViewFactory();
	~ViewFactory();
	 IView* GetViewInstance(int selection);
private:
	IView *view;
};

