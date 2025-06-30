# C-Project

**🧾 University Management System **
**📌 Objective:**
To develop a console-based C program that manages various aspects of university administration, including students, courses, exams, labs, and attendance.

**🧠 Key Modules Implemented:**
👨‍🎓 Student Management
Add Student with unique ID

Stores name, program, semester, and CGPA

Prevents duplication

Displays all registered students

📚 Course Management
Add Course with unique ID

Captures course name and credit hours

Displays list of all available courses

📝 Exam & Lab Scheduling
Add and display exams and lab activities

Input includes: ID, course name, date, and time

Ensures a maximum number of entries (e.g., 10 exams, 5 labs)

📅 Attendance Tracking
Mark daily attendance for each student

Tracks up to 30 days

Displays attendance status (Present/Absent) in tabular form

**🧾 Data Structures Used:**
**struct Student:** ID, name, program, semester, CGPA

**struct Course:** ID, name, credits

struct Exam, struct Lab: ID, course, date, time

**struct Attendance:** studentId, date, isPresent (boolean)

**🛠 Constants:**
MAX_STUDENTS: 100

MAX_COURSES: 10

MAX_EXAMS: 10

MAX_LABS: 5

MAX_ATTENDANCE_DAYS: 30

**🧮 Program Flow:**
Initialize all arrays with default values.

Show menu with options (1–11).

Perform selected action via switch-case.

Allow continuous operation until user chooses Exit.

**📌 Limitations:**
No file storage (data lost on exit).

Attendance marking is manual per student and per day.

No dynamic memory (static arrays only).
