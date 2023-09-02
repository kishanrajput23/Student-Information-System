# Food Ordering System

## How To Setup?

### Step 1:

- First of all download this project in your local system and extract the files. Below are details how you can do that:

1. Click on this green color `Code` Button.

<img width="331" alt="image" src="https://user-images.githubusercontent.com/70385488/223937703-c20e271d-badb-4943-9db8-9ab3adde6ec5.png">

2. In dropdown menu please select `Download ZIP` option.

<img width="400" alt="image" src="https://github.com/kishanrajput23/Student-Information-System/assets/70385488/f3f0d087-10cc-44e5-8766-5ca333d622cd">

3. After downloading `ZIP File` please unzip it.

### Step 2:

- Now please open `SIS` folder in your favourite code editor like `VS Code` or you can open in any other editor.

- After that your code editor should look like below :

<img width="1440" alt="image" src="https://github.com/kishanrajput23/Student-Information-System/assets/70385488/8e89ec45-fd5b-4e70-8643-c6513af55816">

- I hope you have followed all above steps carefully. Now you have to change certain things before running this project.

### Step 3:

- Firstly open `main.cpp` file and it should look like this.

<img width="1440" alt="image" src="https://github.com/kishanrajput23/Student-Information-System/assets/70385488/d08d94fa-0687-436d-8f26-30f73ec69b1d">

- Now if you're getting an error in line number 2 then you have to make some changes otherwise leave it as it is and jump on step 4.
- In line numnber 2 copy the path of `admin.h` file and paste that path in between double quotes `""`. Please make sure that you should not give any other extra spaces in between double quotes.
- For copying path of `admin.h` file, just right click on `admin.h` file which is located in `include` folder and paste it in line number 2.

<img width="489" alt="image" src="https://github.com/kishanrajput23/Student-Information-System/assets/70385488/e9b8cb03-7510-4ff0-a598-b3303a4f30c6">

### Step 4:

- Open `admin.cpp` file which is located in `src` folder.
- Here again if you're getting error in line number 8 then follow above steps to give path of `admin.h` file else leave it as it is and follow below instructions.
- Now you have to make changes in line number 344, 397, 398, 535, 536, 572, 647, 648, 684, 685, 728, 736, 753, 754, and 803 
- So, copy the path of `student_details.csv` file which is located in `data` folder and paste it in line number 344, 397, 535, 572, 647, 684, 728.
- Now in line number 398, 648, 736, 753 and 803 what you need to do is :
```
copy the path of student_details.csv and paste that path.

for example : /Users/KI20449224/Downloads/SIS/data/student_details.csv

now what you need to do is just remove student_details.csv from above path and write temp.csv

after making changes your path will look like this : /Users/KI20449224/Downloads/SIS/data/temp.csv
```
- Now in line number 536 and 685 what you need to do is :
```
the line of code look like this : rename("/Users/KI20449224/Downloads/SIS/data/temp.csv", "/Users/KI20449224/Downloads/SIS/data/student_details.csv");

now what you have to do is, in first "" you have to give path of a file which you gave in line number 398 and after that in second "" you have to give path of student_details.csv file. 
```
- Finally you have made the all changes in `admin.cpp` file. Now Let's discuss how you gonna run this project successfully.


## How To Run?

- So, if you're using `Mac` then it's very simple to run this project. Firstly open `Terminal` and type `cmd + shift + b` then press `Enter`. After that in `Terminal` type `./make` and hit `Enter`.
- Now if you get any error while building make file then follow below steps:
1. Type  `cmd + shift + p` then click `edit json properties`.
2. In `.vscode` folder create a file named as `tasks.json` only if it is not presnt in that folder like below:

<img width="224" alt="image" src="https://github.com/kishanrajput23/Student-Information-System/assets/70385488/35dd602d-0e69-469c-b90e-c00112228366">

3. Open `tasks.json` and paste below code or match the code:
```
{
	"version": "2.0.0",
	"tasks": [
	  {
		"label": "Build",
		"type": "shell",
		"command": "g++",
		"args": [
		  "-std=c++0x",
		  "-o",
		  "make",
		  "main.cpp",
		  "src/admin.cpp",
		  "-arch",
		  "arm64"
		],
		"group": {
		  "kind": "build",
		  "isDefault": true
		}
	  },
	  {
		"label": "Run",
		"type": "shell",
		"command": "${fileDirname}/${fileBasenameNoExtension}"
	  }
	]
  }
```
4. After following above steps your error will be solve.

- Now after running `./make` command the system will give you 2 options and you can perform operations as per your choice:
  
<img width="588" alt="image" src="https://github.com/kishanrajput23/Student-Information-System/assets/70385488/f256db74-4e1a-4078-9bad-a929274d22ea">

**Note:** For admin credentials type `admin` as `username` and `12345` as `password`.

## Still Have Confusion?
- So, after following all above given instructions, still you are facing some difficulties/issues then feel free to reach out to me or just open an issue in this repository and I'll definately get back to you.

## Connect With Me [👤](https://linktr.ee/kishan_rajput23)👈
