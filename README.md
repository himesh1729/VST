## VST WIO Display API
Display Size- 320X240

Connect Wio Terminal to the host device. \
Serial communication **baud rate:115200** 
### Check for device:
Sending **`{whoami}`** will return **WIO**
### Adjust brightness:
Sending **`{B=<int>}`** will adjust brightness **`<int>`** will only accept integer values from **1** to **101**. Will return **OK**. Sending values other than that will return **ERROR**

### Change display text:
Sending **`{S=<string>}`** will display the string. **`<string>`** cannot have **‘{‘** and **‘}’**. Will return **OK**. Wrong format will return **ERROR**

### Examples:
To adjust the brightness to **10**, send **`{B=10}`** \
To change the string value to **BED** send **`{S=BED}`** \
To check the connection and serial device name send **`{whoami}`**
