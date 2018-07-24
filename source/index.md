---
title: 'ECE 387: Intro to Robotic Systems'
header-includes:
    - \usepackage{fancyhdr}
    - \pagestyle{fancy}
    - \fancyhead[CO,CE]{ECE 387}
    - \fancyfoot[CO,CE]{\thepage}
    - \fancyfoot[LE,RO]{Robots are cool!}
---

# ECE382 - Embedded Systems I

| Lsn | Topic                                                 | Quiz | Misc    |
|-----|-------------------------------------------------------|------|---------|
| 1   | [Intro & Overview][1]                                 |      | |
| 2   | [uC Comparison and ISA][2]                            |      | |
| 3   | [ISA: Instructions to Machine Code][3]                |      | |
| 4   | [ISA: Instructions to Machine Code][4]                |      | |
| 5   | [ISA: Instructions to Machine Code][5]                | X    | |
| 6   | [Advanced Git][6]                                     | X    | on-line git homework due at BOC |
| 7   | [Code Composer Studio (CSS)][7]                       |      | |
| 8   | [Status Register and Flow Control][8]                 |      | |
| 9   | [Stack, Subroutines, and ABI][9]                      |      | |
| 10  | [Stack, Subroutines, and ABI][10]                     | X    | |
| 11  | [Lab 1: Assembly Calculator][11]                      |      | |
| 12  | [Lab 1: Assembly Calculator][11]                      |      | |
| 13  | [Memory Mapped IO and Muxes][13]                      |      | |
| 14  | [Polling, Debouncing, and Logic Analyzer][14]         |      | |
| 15  | [Polling, Debouncing, and Logic Analyzer][15]         |      | |
| 16  | [Lab 2: Stoplight][16]                                |      | |
| 17  | [Lab 2: Stoplight][17]                                |      | |
| 18  | [GR1][18]                                             |      | |
| 19  | [GR Review and High Level Language (HLL) Overview][19]|      | |
| 20  | [Intro to C and Flow Control][20]                     |      | |
| 21  | [Programming Libraries][21]                           |      | |
| 22  | [Common Data Structures][22]                          |      | |
| 23  | [Common Data Structures][23]                          | X    | |
| 24  | [Interrupts][24]                                      |      | |
| 25  | [Interrupts][25]                                      |      | |
| 26  | [Serial Comm][26]                                     |      | |
| 27  | [Serial Comm][27]                                     |      | |
| 28  | [Serial Comm][28]                                     | X    | |
| 29  | [Timers][29]                                          |      | |
| 30  | [Timers][30]                                          |      | |
| 31  | [Capture Compare][31]                                 |      | |
| 32  | [Lab 3: IR Remote][32]                                |      | |
| 33  | [Lab 3: IR Remote][33]                                |      | |
| 34  | [Lab 3: IR Remote][34]                                | X    | |
| 35  | [Analog-to-Digital Conversion][35]                    |      | |
| 36  | [Lab 4: Servo Calibrator][36]                         |      | |
| 37  | [Lab 4: Servo Calibrator][37]                         |      | |
| 38  | [Lab 4: Servo Calibrator][38]                         |      | |
| 39  | [GR 2][39]                                            |      | |
| 40  | [Wrap Up][40]                                         |      | |

- Homeworks are at the beginning of class (BOC)
- Labs are due on the final day at the end of class (EOC)

[1]: lessons/lsn1/index.html
[2]: lessons/lsn2/index.html
[3]: lessons/lsn3-4-5/index.html
[4]: lessons/lsn3-4-5/index.html
[5]: lessons/lsn3-4-5/index.html
[6]: lessons/lsn6/index.html
[7]: lessons/lsn7/index.html
[8]: lessons/lsn8/index.html
[9]: lessons/lsn9-10/index.html
[10]: lessons/lsn9-10/index.html
[11]: labs/lab1/index.html
[12]: labs/lab1/index.html
[13]: lessons/lsn13/index.html
[14]: lessons/lsn14-15/index.html
[15]: lessons/lsn14-15/index.html
[16]: labs/lab2/index.html
[17]: labs/lab2/index.html
[18]: labs/lab2/index.html
[19]: lessons/lsn3-4-5/index.html
[20]: lessons/lsn3-4-5/index.html
[21]: lessons/lsn3-4-5/index.html
[22]: lessons/lsn3-4-5/index.html
[23]: lessons/lsn3-4-5/index.html
[24]: lessons/lsn3-4-5/index.html
[25]: lessons/lsn3-4-5/index.html
[26]: lessons/lsn3-4-5/index.html
[27]: lessons/lsn3-4-5/index.html
[28]: lessons/lsn3-4-5/index.html
[29]: lessons/lsn3-4-5/index.html
[30]: lessons/lsn3-4-5/index.html
[31]: lessons/lsn3-4-5/index.html
[32]: lessons/lsn3-4-5/index.html
[33]: lessons/lsn3-4-5/index.html
[34]: lessons/lsn3-4-5/index.html
[35]: lessons/lsn3-4-5/index.html
[36]: lessons/lsn3-4-5/index.html
[37]: lessons/lsn3-4-5/index.html
[38]: lessons/lsn3-4-5/index.html
[39]: lessons/lsn3-4-5/index.html
[40]: lessons/lsn3-4-5/index.html

# [Spring 2018 Syllabus](syllabus.pdf)

## Instructor

  Maj Kevin Walchko
  Fairchild 2F48
  kevin.walchko@usafa.edu

  Capt Dan Johnson
  Fairchild 2F46A
  daniel.johnson@usafa.edu

## Course Goals and Objectives

By the end of this course, cadets shall be able to:

1.	Utilize the built-in functional units of a specified microcontroller.
2.	Write, assemble, link, and run microcontroller code in assembly language.
3.	Write, compile, assemble, link, and run microcontroller code in the C programming language.
4.	Interpret and explain orally and in writing the functions of a given assembly language or C program as well as laboratory work
5.	Evaluate, analyze, debug, and modify a given program to improve its execution of a specified task
6.	Demonstrate a working knowledge of the on-board hardware components of a microcontroller and implement an interface between a specified microcontroller and other hardware.
7.	Demonstrate the ability to solve well and ill-defined problems


### Course Prerequisites

CompSci 110 and ECE 281

## Grades

| Grade        | Grade        |
|--------------|--------------|
| 90 < A < 100 | 74 < C+ < 77 |
| 87 < A- < 90 | 70 < C  < 74 |
| 84 < B+ < 87 | 67 < C- < 70 |
| 80 < B < 84  | 60 < D  < 67 |
| 77 < B- < 80 |  0 < F  < 60 |

|               | Prog %   | Final %   |
|---------------|----------|-----------|
| HW            | xx       | xx        |
| Quizzes       | xx       | xx        |
| GRs           | xx       | xx        |
| Labs          | xx       | xx        |
| Final Exam    |          | xx        |

## Missing Class and the Late Policy

Inform your instructor of absences in advance via email. Please include the reason for the absence and any relevant SCA. Check the SCA to see if instructor permission is required and if it is, make the request prior to the absence. You will be given an Unexcused Absence in CAS if you fail to get permission.

If you plan to miss a class, you *must* take any quiz or GR prior to your departure.

Due to the limited time to conduct labs and the fact they are executed in groups, you can not miss both lab days unless you have a medical excuse due to unplanned illness. You can miss one lab day, but depending on situation (e.g., something you could have avoided), you may loose points for the lab.

If you are expecting to miss class on the day an assignment is due, you shall turn in your assignment prior to your departure. Your instructor may grant a no-penalty turn-in extension for absences resulting from illness or other legitimate extenuating circumstances. Cadets shall coordinate late submittals in advance. The late policy for the Department of Electrical and Computer Engineering is as follows:

| How Late? | Max Penalty | Max Grade |
|-----------|-------------|-----------|
| < 1 day   | 25%         | 75%       |
|   2 day   | 50%         | 50%       |
|   3 day   | 75%         | 25%       |
| > 3 day   | 100%        | 0%        |

## Collaboration and Documentation Policy

You may receive help from any DFEC faculty member on the homework. Do not work
with other students in the class or who have taken the class previously. Document
all help received on work submitted for grading IAW DF policies, or document
*none* if your work was completely individual effort.

### Homework

Reading assignments include the lesson notes provided on each lesson page, along with the links and datasheet pages specified at the top of the respective lesson page.  The Barrett readings are optional.  Readings should be accomplished **prior** to the designated class in order to be most beneficial.

Graded homework assignments are also given at the top of the class notes and are due BOC the next lesson unless otherwise stated.

### Prelabs, Labs, and Lab Notebooks

Prelabs and Labs will be turned in and graded via Bitbucket unless otherwise stated.  **Prelabs are due NLT one duty day prior to the day you start a lab.**  This is to ensure that instructors have a reasonable amount of time to provide you feedback on your plan prior to starting the lab.

Lab notebooks must follow the lab notebook standards specified under the [Lab Notebooks](/382/admin/labs.html) link on the Admin page.  The lab notebook is maintained as a journal of your lab experience and should allow you, or any knowledgeable engineer, to recreate your project.

### Exams

All exams are closed textbook and notes.  Cadets are allowed to use only the provided TI documents and data sheets for exams and quizzes.  Both laboratory and classroom work will appear on exams.  For missed GRs, the following policies are outlined:

- **Scheduled Absence** - If you know that you will be unable to take the GR during the scheduled GR period, you are required to inform your instructor as soon as possible before the GR to schedule a make-up exam.
- **Unscheduled Absense** - If you miss the GR for reasons beyond your control (e.g. hospitalization, emergency leave, delayed field trip return, etc.) you must contact DFEC (x3190) within **two working days** to schedule a make-up.  Exceptions can only be granted by the Department Head.
