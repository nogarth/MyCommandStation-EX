/**********************************************************************

config.h
COPYRIGHT (c) 2020 Fred Decker

The configuration file for DCC-EX Command Station

**********************************************************************/

/////////////////////////////////////////////////////////////////////////////////////
//  NOTE: Before connecting these boards and selecting one in this software
//        check the quick install guides!!! Some of these boards require a voltage
//        generating resitor on the current sense pin of the device. Failure to select
//        the correct resistor could damage the sense pin on your Arduino or destroy
//        the device.
//
// DEFINE MOTOR_SHIELD_TYPE BELOW ACCORDING TO THE FOLLOWING TABLE:
//
//  STANDARD_MOTOR_SHIELD : Arduino Motor shield Rev3 based on the L298 with 18V 2A per channel
//  POLOLU_MOTOR_SHIELD   : Pololu MC33926 Motor Driver (not recommended for prog track)
//  FUNDUMOTO_SHIELD      : Fundumoto Shield, no current sensing (not recommended, no short protection)
//  FIREBOX_MK1           : The Firebox MK1                    
//  FIREBOX_MK1S          : The Firebox MK1S
//  IBT_2_WITH_ARDUINO    : Arduino Motor Shield for PROG and IBT-2 for MAIN
//   |
//   +-----------------------v
//
#define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
/////////////////////////////////////////////////////////////////////////////////////
//
// The IP port to talk to a WIFI or Ethernet shield.
//
#define IP_PORT 2560

/////////////////////////////////////////////////////////////////////////////////////
//
// NOTE: Only supported on Arduino Mega
// Set to false if you not even want it on the Arduino Mega
//
#define ENABLE_WIFI true

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE WiFi Parameters (only in effect if WIFI is on)
//
// If DONT_TOUCH_WIFI_CONF is set, all WIFI config will be done with
// the <+> commands and this sketch will not change anything over
// AT commands and the other WIFI_* defines below do not have any effect.
//#define DONT_TOUCH_WIFI_CONF
//
// WIFI_SSID is the network name IF you want to use your existing home network.
// Do NOT change this if you want to use the WiFi in Access Point (AP) mode. 
//
// If you do NOT set the WIFI_SSID and do NOT set the WIFI_PASSWORD,
// then the WiFi chip will first try to connect to the previously
// configured network and if that fails fall back to Access Point mode.
// The SSID of the AP will be automatically set to DCCEX_*.
// If you DO set the WIFI_SSID then the WiFi chip will try to connect
// to that (home) network in station (client) mode. If a WIFI_PASSWORD
// is set (recommended), that password will be used for AP mode.
// The AP mode password must be at least 8 characters long.
//
// Your SSID may not contain ``"'' (double quote, ASCII 0x22).
#define WIFI_SSID "Your network name"
//
// WIFI_PASSWORD is the network password for your home network or if
// you want to change the password from default AP mode password
// to the AP password you want. 
// Your password may not conain ``"'' (double quote, ASCII 0x22).
#define WIFI_PASSWORD "Your network passwd"
//
// WIFI_HOSTNAME: You probably don't need to change this
#define WIFI_HOSTNAME "dccex"
//
// WIFI_CHANNEL: If the line "#define ENABLE_WIFI true" is uncommented, 
// WiFi will be enabled (Mega only). The default channel is set to "1" whether
// this line exists or not. If you need to use an alternate channel (we recommend
// using only 1,6, or 11) you may change it here.
#define WIFI_CHANNEL 1

/////////////////////////////////////////////////////////////////////////////////////
//
// ENABLE_ETHERNET: Set to true if you have an Arduino Ethernet card (wired). This
// is not for Wifi. You will then need the Arduino Ethernet library as well
//
//#define ENABLE_ETHERNET true


/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE STATIC IP ADDRESS *OR* COMMENT OUT TO USE DHCP
//
//#define IP_ADDRESS { 192, 168, 1, 200 }

//
// ENABLE_MQTT: if set to true you have to have an Arduino Ethernet card (wired). This
// is not for Wifi. You will need the Arduino Ethernet library as well as the PubSub
// library from <add link here> or get via the libray manager either from the IDE
// or PIO

// The following is only needed if the Broker requires it. cf broker descriptions below
#define MQTT_USER   "your broker user name"
#define MQTT_PWD    "your broker passwd"
#define MQTT_PREFIX "prefix if required by the broker"

// UNCOMMENT THE FOLLOWING LINE TO ENABLE MQTT 
// #define ENABLE_MQTT true

// Set the used broker to one of the configurations from MQTTBrokers.h where some
// public freely avaiable brokers are configured

// DEFINE THE MQTT BROKER BELOW ACCORDING TO THE FOLLOWING TABLE:
//
//  DCCEX_MQTT_BROKER : DCCEX Team best effort operated MQTT broker; pls apply for user/pwd on discord in the mqtt channel if you want to try it
//  DCCEX_MOSQUITTO   : Mosquitto.org public test broker no user / pwd required so anyone can subscribe/publish to any topic here; good for testing only
//  DCCEX_HIVEMQ      : Provided by HiveMQ; Public no user / pwd required 
//   |
//   +-----------------------v

#define CSMQTTBROKER DCCEX_MOSQUITTO

// --------------------------
// CUSTOMIZED EXAMPLE
// Configuration for a broker installed on a machine on you home netowrk where the IP address of the machine runing the broker
// is 192.168.0.2 and requires user authentication. The uid ad pwd are set in the config.h file 

//                                                             Port     IPAddress      Username (opt)  Password(opt)  Prefix (opt)             
// #define MY_PERSONAL_BROKER F("MYBROKERMQ"), new MQTTBroker( 1883, {192, 168, 0, 2}, F("username"), F("password"), F("prefix-if-required"))
//
// If you have access to a broker on the internet replace the IPAddress by F("my-broker-domain-name")
// -------------------------


/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE LCD SCREEN USAGE BY THE BASE STATION
//
// Note: This feature requires an I2C enabled LCD screen using a PCF8574 based chipset.
//       or one using a Hitachi  HD44780.
//       OR an I2C Oled screen.
// To enable, uncomment one of the lines below

// define LCD_DRIVER for I2C LCD address 0x3f,16 cols, 2 rows
// #define LCD_DRIVER  0x3F,16,2

//OR define OLED_DRIVER width,height in pixels (address auto detected)
// 128x32 or 128x64 I2C SSD1306-based devices are supported.
// Also 132x64 I2C SH1106 devices.
// #define OLED_DRIVER 128,32

/////////////////////////////////////////////////////////////////////////////////////

