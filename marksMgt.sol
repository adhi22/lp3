// SPDX-License-Identifier: SEE LICENSE IN LICENSE
pragma solidity >= 0.7.0;

contract StudentManagement {

    struct Student {
        int id;
        string name;
        int marks;
    }

    Student[] Students;

    function addStudent(
        int id, 
        string memory name, 
        int marks
    ) public {
        Student memory stud = Student(id, name, marks);
        Students.push(stud);
    }

    function getStudent(int id) public view returns (string memory, int) {
        for(uint i=0; i<Students.length; i++) {
            Student memory stud = Students[i];
            if(stud.id == id) return (stud.name, stud.marks);
        }
        return ("No information found", 0);
    }

    fallback() external {
        x = x + 1;
    }

    uint256 x;

}