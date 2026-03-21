Use IFTTT for Web Service — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [Example Guides](../index.html)
- [HTTP](index.html)
- Use IFTTT for Web Service
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/Example_Guides/HTTP/Use IFTTT for Web Service.rst)
# Use IFTTT for Web Service[](#use-ifttt-for-web-service)
## Introduction to IFTTT[](#introduction-to-ifttt)
IFTTT, known as If This Then That, is a website and mobile app and free web-based service to create the applets, or the chains of simple
conditional statements. The applet is triggered by changes that occur
within other web services such as Gmail, Facebook, Telegram, Instagram,
Pinterest etc.
## Preparation[](#preparation)
- [AMB82-mini](https://www.amebaiot.com/en/where-to-buy-link/#buy_amb82_mini) x 1
- An account from [https://ifttt.com/](https://ifttt.com/), to access IFTTT service*
[](../../../../_images/image01135.png)
*Note: Upon log in, there are several cloud and online services that
are integrated with IFTTT platforms. Some IFTTT services may require
IFTTT Pro+, that is an online billing service.
## Example[](#example)
- Generate Applet from IFTTT
In this example, we obtain an example of IFTTT Applet to send email to specified recipient.
To run the example, HTTP POST feature of the Ameba is used to post a simple webhook service that is received by IFTTT platform and in turn be used to trigger a response (sending an email).
After logging in [https://ifttt.com/](https://ifttt.com/), click **Create** from the top bar.
[](../../../../_images/image02130.png)
Click “Add” to add the trigger.
[](../../../../_images/image03109.png)
Choose Webhooks service as shown below. Alternatively, search the service by typing into the search bar.
[](../../../../_images/image0489.png)
After that, the available triggers will appear. Choose “Receive a Web request”.
[](../../../../_images/image0574.png)
Next, an Event Name is required to identify the trigger successfully. In this example, set the Event name as “test_event”.
[](../../../../_images/image0667.png)
Next, click Add in Then That field to create the action service taken in response to the last trigger.
[](../../../../_images/image0762.png)
Choose Email as the action service.
[](../../../../_images/image0853.png)
Click on Send me an email.
[](../../../../_images/image0949.png)
Under the template of Send me an Email, the contents of the email, such as subject and body is editable. Click Create Action to complete the
action. Take note that Email service is offered to the email address registered under IFTTT account.
[](../../../../_images/image1045.png)
- Post the Trigger via Ameba
Once the Applet is ready in the IFTTT dashboard, the example program can be flashed onto the Ameba board to post the HTTP request.
Open the example code in File -> Examples -> AmebaHttp -> HTTP_IFTTT_Post
[](../../../../_images/image1135.png)
In the example program, edit the following 3 items inside the code to make the program work.
- The WiFi credentials to connect to the Wi-Fi hotspot or access point of desirable choice.
- Under the Host name field, enter the host name of the IFTTT service “maker.ifttt.com”.
- Under the Path name field, enter the “Event name” and key field “/trigger/Event name/with/key/Key Field”.
- Event name: The event name should be the same as the one specified in the IFTTT applet. In this example, the event name is “test_event”.
- Key Field: Available under webhook service in individual IFTTT account. See the next step for the steps to obtain the Key Field.
[](../../../../_images/image1229.png)
To obtain a key from documentation tab of the Webhooks, find the webhook service in the Explore tab.
[](../../../../_images/image1327.png)
On the Webhooks service page, click on the “Documentation” tab.
[](../../../../_images/image1422.png)
The key can be found in the documentation page. Also, information on how HTTP request can be used.
[](../../../../_images/image1519.png)
Once the example is ready, Connect the Ameba board via USB cable.
On the Arduino IDE, compile the code and upload the code onto Ameba
and press the reset button. After the event has been successfully
fired, “Congratulations! You have fired the test_event event” can be
seen on the serial monitor and an email reminder for this event will
be delivered.
[](../../../../_images/image1615.png)
Thereafter an email is sent to recipient email account registered at
IFTTT Applet and an email will be received.
[](../../../../_images/image1714.png)
- IFTTT Line Notify
Alternatively, an example to send a message with the LINE messaging app
on iPhone or Android using IFTTT Applet is available. It can be achieved
by modifying the “Then That” settings.
You may follow the same steps previously in “Generate Applet from IFTTT”
section to create a Webhooks service as the trigger. The Event Name
required to identify the trigger will remain as “test_event”. Next,
click the “Add” button in “Then That” field to create the action service
taken in response to the last trigger.
[](../../../../_images/image1810.png)
Choose Line as the action service.
[](../../../../_images/image198.png)
Click on “Send message”.
[](../../../../_images/image207.png)
Click on “Connect” and login to your Line Account.
[](../../../../_images/image215.png)
Select LINE account, set the Recipient to “1-on-1 chat with LINE Notify”
which means the message triggered by IFTTT will directly send to your
chats. Next, input your desired message in the input box under
“Message”. For sending images, you can insert a link to your photo in
the input box under “Photo URL”.
[](../../../../_images/image225.png)
On the Arduino IDE, compile the code and upload the code onto Ameba and
press the reset button. After the event has been successfully fired, you
will receive a message from “LINE Notify” on your Mobile devices or PC.
[](../../../../_images/image235.png)
[ Previous](Retrieve%20HTTP%20webs.html)
[Next ](../I2C/index.html)
[
](https://github.com/search?q=topic%3Aarduino+org%3AAmeba-AIoT&type=Repositories)
[
](https://www.youtube.com/@amebaiot7033)
[
](https://www.facebook.com/groups/amebaioten)
[
](https://www.facebook.com/groups/AmebaIoT)
[
](https://space.bilibili.com/457777430)
© Copyright 2026 Realtek Semiconductor Corp. All rights reserved.