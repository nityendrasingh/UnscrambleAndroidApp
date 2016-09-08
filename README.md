# UnscrambleAndroidApp
Let’s Unscramble Android Part

By: Nityendra Singh

Unscramble Game is developed using android app (client side) and C (server side). This android app is a multiplayer game in which the game can be started by any one of the clients currently logged in. Android app part of Unscramble Game was done using two activities 1. ServerLoginScreen.java and 2. StartGameScreen.java.

[1] ServerLoginScreen.java: This activity get multiple parameters from screen such as serverIP, serverPort and clientName (EditText). serverIP and serverPort are hidden and hardcoded behind the screen. ClientName is to be filled by the user. A default clientName is given when user clicks “CONNECT” button without entering any text. Button calls a new onClickListener method that sends three parameters (discussed above) to second activity (i.e. StartGameScreen). Sending of parameters is done by Intent.

[2] StartGameScreen.java: This activity contains all the display related logic as well as socket related function calls. This activity works on two threads. Base thread is responsible for sending all the messages to server. Second thread (created from base) is responsible for receiving messages from server. Both threads (sending and receiving) happens independently. This activity has multiple modes:

Mode 1: When clients are joining the server. A message at the top would be displayed that says the clientNames of all the clients logged in. This message gets updated whenever a new client login.

Mode 2: When one client click the start button, a scrambled word is shown on the screen. Clients are expected to send their answer through EditText just below the scrambled word.

Mode 3: When game ends, winner is displayed. If you lose then correct unscrambled word is also shown on the screen. This mode allows clients to restart game again. This document has screenshots and code attached.

[SCREENSHOTS](pics/)
