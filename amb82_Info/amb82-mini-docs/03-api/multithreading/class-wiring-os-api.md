Class Wiring OS API — Ameba Arduino AIoT Documentation v1.1 documentation
- 
[](../../../../index.html)
- [AMB82-mini Arduino](../../index.html)
- [API Documents](../index.html)
- [Multithreading](index.html)
- Class Wiring OS API
- 
[ Edit on GitHub](https://github.com/Ameba-AIoT/ameba-arduino-doc/blob/main/source/ameba_pro2/amb82-mini/API_Documents/Multithreading/Class Wiring OS API.rst)
# Class Wiring OS API[](#class-wiring-os-api)
## **Wiring OS API Class**[](#wiring-os-api-class)
### **Description**[](#description)
A wrapper to CMSIS (Cortex Microcontroller Software Interface Standard) OS API which serve as a RTOS to create multi-threaded application with real-time behaviour.
### **Syntax**[](#syntax)
NA
### **Members**[](#members)
|**Public Methods**
|
|
| os_thread_create_arduino
|
Create a thread and add it to
Active Threads and set it to state
READY
|
|
| os_thread_get_id_arduino
|
Return the thread ID of the
current running thread
|
|
| os_thread_terminate_arduino
|
Terminate execution of a thread
and remove it from Active Threads
|
|
| os_thread_yield_arduino
|
Pass control to next thread that
is in state READY
|
|
| os_thread_set_priority_arduino
|
Change priority of an active
thread
|
|
| os_thread_get_priority_arduino
|
Get current priority of an active
thread
|
|
| os_signal_set_arduino
|
Set the specified Signal Flags of
an active thread
|
|
| os_signal_clear_arduino
|
Clear the specified Signal Flags
of an active thread
|
|
| os_signal_wait_arduino
|
Wait for one or more Signal Flags
to become signaled for the current
RUNNING thread
|
|
| os_timer_create_arduino
|
Create a timer
|
|
| os_timer_start_arduino
|
Start or restart a timer
|
|
| os_timer_stop_arduino
|
Stop the timer
|
|
| os_timer_delete_arduino
|
Delete a timer that was created by
os_timer_create
|
|
| os_semaphore_create_arduino
|
Create and Initialize a Semaphore
object used for managing resources
|
|
| os_semaphore_wait_arduino
|
Wait until a Semaphore token
becomes available
|
|
| os_semaphore_release_arduino
|
Release a Semaphore token
|
|
| os_semaphore_delete_arduino
|
Delete a Semaphore that was
created by os_semaphore_create
|
|
| os_get_free_heap_size_arduino
|
Return the available heap memory
space when called
|
|
## **os_thread_create_arduino**[](#os-thread-create-arduino)
### **Description**[](#id1)
Create a thread and add it to Active Threads and set it to state READY.
### **Syntax**[](#id2)
uint32_t os_thread_create_arduino (void (*task)(const void *argument), void *argument, int priority, uint32_t stack_size);
### **Parameters**[](#parameters)
`task`: task Function pointer which is the thread body. It should not run into the end of function unless os_thread_terminate is invoked
`argument`: The pointer that is passed to the thread function as start argument.
`priority`: The underlying os is FreeRTOS. It executes tasks with highest priority which are not in idle state.
`stack_size`: The stack_size is used as memory heap only for this task.
### **Returns**[](#returns)
This function returns the thread ID in 32-bit which is used in thread operation for reference by other functions or NULL in case of error.
### **Example Code**[](#example-code)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_thread_get_id_arduino**[](#os-thread-get-id-arduino)
### **Description**[](#id3)
Get the thread ID of the current running thread.
### **Syntax**[](#id4)
uint32_t os_thread_get_id_arduino (void);
### **Parameters**[](#id5)
NA
### **Returns**[](#id6)
This function returns current thread id in 32-bit which calls os_thread_get_id_arduino.
### **Example Code**[](#id7)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_thread_terminate_arduino**[](#os-thread-terminate-arduino)
### **Description**[](#id8)
Terminate execution of a thread and remove it from Active Threads.
### **Syntax**[](#id9)
uint32_t os_thread_terminate_arduino (uint32_t thread_id);
### **Parameters**[](#id10)
`thread_id`: Terminate the thread with specific thread_id
### **Returns**[](#id11)
This function returns the os_status code.
### **Example Code**[](#id12)
NA
Important
Thread should not end without terminate first.
Note
“wiring_os.h” must be included to use the class function.
## **os_thread_yield_arduino**[](#os-thread-yield-arduino)
### **Description**[](#id13)
Pass control to next thread that is in READY state
### **Syntax**[](#id14)
uint32_t os_thread_yield_arduino (void);
### **Parameters**[](#id15)
NA
### **Returns**[](#id16)
This function returns the os_status code.
### **Example Code**[](#id17)
NA
Important
The smallest execution unit by default is one millisecond. When a thread with a lower priority wants to instantly give execution rights to a thread with a higher priority rather than waiting for the current 1 millisecond to expire, calling os_thread yield can transfer execution rights to the OS’s idle task and determine which thread will execute next.
Note
“wiring_os.h” must be included to use the class function.
## **os_thread_set_priority_arduino**[](#os-thread-set-priority-arduino)
### **Description**[](#id18)
Change priority of an active thread.
### **Syntax**[](#id19)
uint32_t os_thread_set_priority_arduino (uint32_t thread_id, int priority);
### **Parameters**[](#id20)
`thread_id`: Thread ID identifies the thread (pointer to a thread control block).
`priority`: The updated priority
### **Returns**[](#id21)
This function returns os_status code.
### **Example Code**[](#id22)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_thread_get_priority_arduino**[](#os-thread-get-priority-arduino)
### **Description**[](#id23)
Get current priority of an active thread.
### **Syntax**[](#id24)
uint32_t os_thread_get_priority_arduino (uint32_t thread_id);
### **Parameters**[](#id25)
`thread_id`: The target thread with the thread id to be searched
### **Returns**[](#id26)
This function returns os_priority.
### **Example Code**[](#id27)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_signal_set_arduino**[](#os-signal-set-arduino)
### **Description**[](#id28)
Set the specified Signal Flags of an active thread.
### **Syntax**[](#id29)
int32_t os_signal_set_arduino (uint32_t thread_id, int32_t signals);
### **Parameters**[](#id30)
`thread_id`: Thread ID obtained by os_thread_create_arduino or
`os_thread_get_id_arduino.signals`: The signal flags of the thread that should be set.
### **Returns**[](#id31)
This function returns previous signal flags of the specified thread or 0x80000000 in case of incorrect parameters.
### **Example Code**[](#id32)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_signal_clear_arduino**[](#os-signal-clear-arduino)
### **Description**[](#id33)
Clear the specified Signal Flags of an active thread.
### **Syntax**[](#id34)
int32_t os_signal_clear_arduino (uint32_t thread_id, int32_t signals);
### **Parameters**[](#id35)
`thread_id`: Clear signal to a thread with the thread_id
`signals`: The signal flags of the thread that shall be cleared.
### **Returns**[](#id36)
This function returns previous signal flags of the specified thread or 0x80000000 in case of incorrect parameters.
### **Example Code**[](#id37)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_signal_wait_arduino**[](#os-signal-wait-arduino)
### **Description**[](#id38)
Wait for one or more Signal Flags to become signalled for the current RUNNING thread.
### **Syntax**[](#id39)
os_event_t os_signal_wait_arduino (int32_t signals, uint32_t millisec);
### **Parameters**[](#id40)
`signals`: the signals to be wait
`millisec`: the timeout value if no signal comes in (in ms). (Acceptable range: 0 - 0xFFFFFFFF, 0 indicates no timeout, 0xFFFFFFFF indicates infinite timeout)
### **Returns**[](#id41)
This function returns event flag information or error code.
### **Example Code**[](#id42)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_timer_create_arduino**[](#os-timer-create-arduino)
### **Description**[](#id43)
Create a timer.
### **Syntax**[](#id44)
uint32_t os_timer_create_arduino (void (*callback)(void const *argument), uint8_t isPeriodic, void *argument);
### **Parameters**[](#id45)
`callback`: The function to be invoke when timer timeout
`isPeriodic`: OS_TIMER_ONCE or OS_TIMER_PERIODIC
`argument`: The argument that is brought into callback function
### **Returns**[](#id46)
This function returns the timer id.
### **Example Code**[](#id47)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_timer_start_arduino**[](#os-timer-start-arduino)
### **Description**[](#id48)
Start or restart a timer.
### **Syntax**[](#id49)
uint32_t os_timer_start_arduino (uint32_t timer_id, uint32_t millisec);
### **Parameters**[](#id50)
`timer_id`: The timer id obtained from os_timer_create
`millisec`: The delay after timer starts (in ms) (Acceptable range: 0 - 0xFFFFFFFF, 0 indicates no timeout, 0xFFFFFFFF indicates infinite timeout)
### **Returns**[](#id51)
This function returns os_status code.
### **Example Code**[](#id52)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_timer_stop_arduino**[](#os-timer-stop-arduino)
### **Description**[](#id53)
Stop the timer.
### **Syntax**[](#id54)
uint32_t os_timer_stop_arduino (uint32_t timer_id);
### **Parameters**[](#id55)
`timer_id`: The timer id obtained from os_timer_create
### **Returns**[](#id56)
This function returns os_status code.
### **Example Code**[](#id57)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_timer_delete_arduino**[](#os-timer-delete-arduino)
### **Description**[](#id58)
Delete a timer that was created by “os_timer_create_arduino”.
### **Syntax**[](#id59)
uint32_t os_timer_delete_arduino(uint32_t timer_id);
### **Parameters**[](#id60)
`timer_id`: The timer id obtained from os_timer_create
### **Returns**[](#id61)
This function returns os_status code.
### **Example Code**[](#id62)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_semaphore_create_arduino**[](#os-semaphore-create-arduino)
### **Description**[](#id63)
Create and initialize a Semaphore object used for managing resources.
### **Syntax**[](#id64)
uint32_t os_semaphore_create_arduino (int32_t count);
### **Parameters**[](#id65)
`count`: The number of available resources
### **Returns**[](#id66)
This function returns semaphore ID.
### **Example Code**[](#id67)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_semaphore_wait_arduino**[](#os-semaphore-wait-arduino)
### **Description**[](#id68)
Wait until a Semaphore token becomes available.
### **Syntax**[](#id69)
int32_t os_semaphore_wait_arduino (uint32_t semaphore_id, uint32_t millisec);
### **Parameters**[](#id70)
`semaphore_id`: semaphore id obtained from os_semaphore_create
`millisec`: timeout value (in ms). (Acceptable range: 0 - 0xFFFFFFFF, 0 indicates no timeout, 0xFFFFFFFF indicates infinite timeout)
### **Returns**[](#id71)
This function returns “1” if “os_semaphoe_wait_arduino” gets the available semaphore token, otherwise returns “0”.
### **Example Code**[](#id72)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_semaphore_release_arduino**[](#os-semaphore-release-arduino)
### **Description**[](#id73)
Release a Semaphore token.
### **Syntax**[](#id74)
uint32_t os_semaphore_release_arduino (uint32_t semaphore_id);
### **Parameters**[](#id75)
`semaphore_id`: semaphore id obtained from os_semaphore_create
### **Returns**[](#id76)
This function returns os_status code that indicates the execution status of the function.
### **Example Code**[](#id77)
NA
Note
“wiring_os.h” must be included to use the class function.
## **os_semaphore_delete_arduino**[](#os-semaphore-delete-arduino)
### **Description**[](#id78)
Delete a Semaphore that was created by os_semaphore_create
### **Syntax**[](#id79)
uint32_t os_semaphore_delete_arduino (uint32_t semaphore_id);
### **Parameters**[](#id80)
`semaphore_id`: semaphore id obtained from os_semaphore_create
### **Returns**[](#id81)
This function returns os_status code that indicates the execution status of the function.
### **Example Code**[](#id82)
NA
Important
“os_semaphore_delete_arduino” shall be consistent in every CMSIS_RTOS.
Note
“wiring_os.h” must be included to use the class function.
## **os_get_free_heap_size_arduino**[](#os-get-free-heap-size-arduino)
### **Description**[](#id83)
Get the available heap memory space when called.
### **Syntax**[](#id84)
size_t os_get_free_heap_size_arduino (void);
### **Parameters**[](#id85)
NA
### **Returns**[](#id86)
This function returns the current free heap size as unsigned integer.
### **Example Code**[](#id87)
NA
Note
“wiring_os.h” must be included to use the class function.
[ Previous](index.html)
[Next ](../NeuralNetwork/index.html)
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