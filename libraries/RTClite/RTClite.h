// Adapted from public domain code by JeeLabs http://news.jeelabs.org/code/

// Simple general-purpose date/time class (no TZ / DST / leap second handling!)
class DateTime {
 public:
  DateTime(uint32_t t=0);
  DateTime(uint16_t year, uint8_t month, uint8_t day,
    uint8_t hour=0, uint8_t min=0, uint8_t sec=0);
  DateTime(const char* date, const char* time);
  uint16_t year() const   { return 2000 + yOff; }
  uint8_t  month() const  { return m; }
  uint8_t  day() const    { return d; }
  uint8_t  hour() const   { return hh; }
  uint8_t  minute() const { return mm; }
  uint8_t  second() const { return ss; }
  uint8_t  dayOfWeek() const;

 protected:
  uint8_t yOff, m, d, hh, mm, ss;
};

// RTC based on the DS1307 chip connected via I2C and the Wire library
class RTC_DS1307 {
 public:
  static int8_t   begin(void);
  uint8_t         isrunning(void);
  static void     adjust(const DateTime& dt);
  static DateTime now();
};
