# dont-look

### Summary
Desktop application that prevents people from shoulder surfing.

### Inspiration
Privacy is an important part of our day to day lives, and the focus is mainly on online security. However, how do we secure our privacy in public when using our laptops? Many times in lectures or coffee shops, people are looking over your shoulder to see what you're doing, and most of the time you don't even realize this. This is why we thought of the Don't Look desktop application. In order to protect our privacy, we should start on the real world.

### What it does
If multiple faces are detected for an extended period of time, this implies someone is looking at your screen. When this happens, a variety of things can happen depending on the settings. These include: dimming screen or giving a notification to the user.

### How we built it
It uses the OpenCV library to detect faces with your camera. Simply using a timer to detect how long a face is in the direction of your computer will actuate either a notification or dimming of the screen till this face looks away.

### Challenges we ran into:
Making it cross compatible for all operating systems. This especially was true when dimming screens as apple required AppleScript to dim; whereas other operating systems had their unique quirks.

### Accomplishments we are proud of:
It works! We managed to finish everything we wanted to implement, other than a few bonus features.

### What's next for Don't Look
Don't look will eventually be a full featured program that protects a users privacy in the real and online world.

### Made With:
C++, Java, Applescript and OpenCV libraries

###### Made at the Local Hack Day hackathon on December 3rd, 2016
