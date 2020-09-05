#pragma once
#include "Node.h"

struct CostNoDepthFunctor
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->cost) > (rhs->cost);
	}
};