# CPSC334--HW4
Motors project - GAPE


*Introduction*

GAPE is an interactive sculpture in which an audience member touches a hand and causes,
depending on the strength of the touch, a sleeping face to in succession open its eyes,
then its mouth, and then vibrate its tongue. The artwork is both an experiment with
materials and engineering, and a simulation of a small and gentle human interaction,
exploring the ways that even such a small moment can be mediated by machines.

*Hardware*

1 ESP32
1 mini servo motor
1 5-12v stepper motor
1 mini vibrating motor
1 ceramic plate piezoelectric sensor
Assorted jumpers and wires
1 breadboard

*Other materials*

Sculpting wire
Paper
Acrylic paint
Hot glue
Wood box structure 16" tall x 14" wide x 12" deep
Hand-shaped wood cutout
Foam
Cardboard

*The sculpture*

The face is constructed from a wire armature, covered with painted, cut-out planes
of painted paper, affixed with hot glue. The eye lids are glued to long a wire that
acts as an axle, extending through holes in either side wall of the wood frame. The
jaw is on a similar, lower wire axle. The extensions of the axles past the wall of
box are connected to the servo and stepper motors respectively, held on cardboard
platforms on the outside of the side wall. The tongue is loose on a further back wire
axle, such that it can rotate freely up and down, and the vibrating motor is placed
beneath it from the back.
The hand is attached such that it extends from the side of the box. The piezo sensor is
taped down to the wood surface, and foam is cut to shape and layered over that. A final
sheet of painted paper brings the hand into the world of the sculpture.
The piezo and all the motors are wired into the ESP32, which is held in a cardboard
cradle in the back of the box.

*The code*

The code is simple and is all run in a single Arduino script flashed onto the ESP.
The script reads values continuously from the piezo. Because the piezo tends to read
a lot of noise, the script waits for large changes in values before taking a touch
reading. 
When it detects a touch, the code scales the voltage reading down to the correct
parameter ranges for each of the motors. As the voltage increases, roughly at one-
third the maximum voltage intervals, one more of the actuators is activated.
At the end of an actuation cycle, the script returns the motors to their resting
positions.
