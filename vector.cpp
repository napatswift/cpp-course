#include <iostream>
using namespace std;

class Vector{
	private:
		int start_x_, start_y_;
		int end_x_, end_y_;

	public:
		Vector(int sx,int sy, int ex, int ey): start_x_(sx), start_y_(sy),
					end_x_(ex), end_y_(ey) {}
		/* this: (1, 1) -> (2, 2)
		 * other: (10, 10) -> (20, 20)
		 * result: (11, 11) -> (22, 22)
		 */

		Vector Add(Vector other){
			int result_sx = this->start_x_ + other.start_x_;
			int result_sy = this->start_y_ + other.start_y_;
			int result_ex = this->end_x_ + other.end_x_;
			int result_ey = this->end_y_ + other.end_y_;
			Vector result(result_sx, result_sy, result_ex, result_ey);
			return result;
		}

};

int main(){
	Vector v1(1,1,2,2);
	Vector v2(10, 10, 20, 20);
	Vector v3 = v1.Add(v2);
}
