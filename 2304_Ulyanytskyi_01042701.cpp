#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>


using namespace std;

class student {
private:
    string first_name;
    string last_name;
    double average_score;

public:
    student(string first_name, string last_name, double average_score)
        : first_name(first_name), last_name(last_name), average_score(average_score) 
    {}

    string get_full_name() const { return first_name + " " + last_name; }

    double get_average_score() const { return average_score; }

    void display_student(int student_number)
    {
        cout << "Student " << student_number << ": " << get_full_name();
        cout << " has score " << average_score << endl;
    }
};

int main() {
    vector<student> students;

    students.push_back(student("Bob1", "Smith1", 75.3));
    students.push_back(student("Bob2", "Smith2", 92.3));
    students.push_back(student("Bob3", "Smith3", 83.9));
    students.push_back(student("Bob4", "Smith4", 91.6));

    auto max_score_student = max_element(students.begin(), students.end(),
        [](const student& s1, const student& s2) {
            return s1.get_average_score() < s2.get_average_score();
        });

    for (int i = 0; i < students.size(); ++i)
        students[i].display_student(i + 1);

    if (max_score_student != students.end()) {
        cout << "Student with the highest score: " << max_score_student->get_full_name();
        cout << " with score " << max_score_student->get_average_score();
    }
    else {
        cout << "No students found\n";
    }

    return 0;
}
