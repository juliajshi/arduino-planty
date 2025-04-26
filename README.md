# arduino-planty

Automatic plant watering system for a single plant. Diagram and code are included in the repository.

How it works: soil hydration sensor will sense hydration levels. When hydration levels drop below 40% (change % for individual plant), the relay is activated and water is pumped via a submersible pump until the hydration levels return to the accepted range.

This is an early version. Next steps may include:

- Adding an on/off switch
- Adding intermittent sampling (daily)
- Calculating how much water to dispense
- Etc.

# COMPONENTS

- Arduino Uno R4
- Breadboard
- Capacitive Soil Moisture Sensor
- 5V Relay
- 3V - 5V Submersible Water Pump
- 2 AA Battery Holder
- 9V Battery with Barrel Jack Connector (optional)

# DIAGRAM

<img align="center" src="https://github.com/user-attachments/assets/2e1a04f3-41ad-4d17-aea6-f46dacde4115" style="max-width:100%;" height="500">
