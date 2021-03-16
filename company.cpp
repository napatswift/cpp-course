#include <iostream>
using namespace std;

class Employee{
	private:
		string name_;
		double salary_;
	public:
		Employee(string name, double salary)
			: name_(name), salary_(salary){}
		void RaiseSalary(double percent){
			salary_ += (salary_ * percent);
		}
		string GetName() const {
			return name_;
		}
		double GetSalary() const{
			return salary_;
		}
};

class Company {
	private:
		string name_;
		string address_;
		Employee **employees_;
		int emp_size_;
	public:
		Company(string n): name_(n) {
				employees_ = new Employee*[5];
				emp_size_ = 0;
			}
		void AddEmployee(Employee *employee){
			if(emp_size_ < 5)
				employees_[emp_size_++] = employee;
		}
		void RaiseAll(double percent){
			int i;
			for (i = 0; i < emp_size_; i++)
				employees_[i]->RaiseSalary(percent);
		}
		double GetTotalSalary(){
			int i;
			double total;
			for (i = 0; i < emp_size_; i++)
				total += employees_[i]->GetSalary();
			return total;
		}
};

int main(){
	return 0;
}
