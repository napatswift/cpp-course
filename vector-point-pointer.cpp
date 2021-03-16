#include <iostream>
using namespace std;

class Point{
	private:
		int x_, y_;
	public:
		Point(int x, int y): x_(x), y_(y) {}
		Point Add(Point other) const{
			int result_x = this->x_ + other.x_;
			int result_y = this->y_ + other.y_;
			Point result(result_x, result_y);
			return result;
		}
		string ToString() const{
			return "(" + to_string(x_) + ", "
				+ to_string(y_) + ")";
		}
};

class Vector{
	private:
		Point start_;
		Point end_;

	public:
		Vector(Point s, Point e): start_(e), end_(e) {}

		/* this: (1, 1) -> (2, 2)
		 * other: (10, 10) -> (20, 20)
		 * result: (11, 11) -> (22, 22)
		 */

		Vector Add(Vector other) const{
			Point result_start = start_.Add(other.start_);
			Point result_end = end_.Add(other.end_);
			Vector result(result_start, result_end);
			return result;
		}
		string ToString() const{
			return start_.ToString() + " --> " + end_.ToString();
		}
};

int main(){
    Point p1(1,1), p2(3,3);
    Vector v1(p1,p2);

    Point pAdd = p1.Add(p2);
    cout << "  p1: " << p1.ToString() << endl;
    cout << "  p2: " << p2.ToString() << endl;
    cout << "pAdd: " << pAdd.ToString() << endl;
    cout << "  v1: " << v1.ToString() << endl;

    return 0;
}
