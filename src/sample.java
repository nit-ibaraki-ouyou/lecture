class Date {
  private int year;
  private int month;
  private int day;
  public int getYear() {
    return year;
  }
  public void setYear(int y) {
    year = y;
  }
  public int getMonth() {
    return month;
  }
  public void setMonth(int m) {
    month = m;
  }
  public int getDay() {
    return day;
  }
  public void setDay(int d) {
    day = d;
  }
  public void show() {
    System.out.printf("%d/%d/%d\n", 
                      year, month, day);
  }
  public Date() {
    year = 1970;
    month = 1;
    day = 1;
  }
  public Date(int y) {
    year = y;
    month = 1;
    day = 1;
  }
}

class Time {
  private int hour;
  private int minute;
  public int getHour() {
    return hour;
  }
  public void setHour(int hour) {
    this.hour = hour;
  }
  public int getMinute() {
    return minute;
  }
  public void setMinute(int minute) {
    this.minute = minute;
  }
  public void show() {
    System.out.printf("%d:%d\n", hour, minute);
  }
  public Time() {
    hour = 10;
    minute = 0;
  }
  public Time(int h) {
    hour = h;
    minute = 0;
  }
}

class Schedule {
  protected String name;
  protected Date date;
  public String getName() {
    return name;
  }
  public void setName(String n) {
    name = n;
  }
  public Date getDate() {
    return date;
  }
  public void setDate(Date d) {
    date = d;
  }
  public void show() {
    System.out.printf("name: %s\n", name);
    date.show();
  }
}

class ScheduleTime extends Schedule {
  private Time time;
  public Time getTime() {
    return time;
  }

  public void setTime(Time t) {
    time = t;
  }
  public void show() {
    super.show();
    time.show();
  }
}

class ScheduleList {
  private ScheduleTime[] list;
  public ScheduleList() {
    list = new ScheduleTime[5];
  }
  public ScheduleTime getSchedule(int i) {
    return list[i];
  }
  public void setSchedule(int i, 
                          ScheduleTime st) {
    list[i] = st;
  }
  public void show() {
    int i;
    for(i=0; i<list.length; i++) {
      if(list[i] != null) {
        System.out.printf("--%d--\n", i);
        list[i].show();
      }
    }
  }
}

class ScheduleMain {
  public static void main(String[] args) {
    Date d = new Date(2012);
    d.show();
    Time t = new Time(15);
    Schedule s = new Schedule();
    s.setName("!!!");
    s.setDate(d);
    s.show();
    ScheduleTime st = new ScheduleTime();
    st.setName("???");
    st.setDate(d);
    st.setTime(t);
    st.show();
    
    ScheduleList sl = new ScheduleList();
    sl.setSchedule(2, st);
    sl.show();
  }
}
