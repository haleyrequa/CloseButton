#pragma once


struct Point {
	float x;
	float y;

	bool operator==(const Point& p)const {
		return (x == p.x && y == p.y);
	}

	bool operator!=(const Point& p)const {
		return (x != p.x || y != p.y);
	}

	bool operator>(const Point& p)const {
		return (x > p.x && y > p.y);
	}

	bool operator<(const Point& p)const {
		return (x < p.x && y < p.y);
	}

	bool operator>=(const Point& p)const {
		return (x >= p.x && y >= p.y);
	}

	bool operator<=(const Point& p)const {
		return (x <= p.x && y <= p.y);
	}
};

