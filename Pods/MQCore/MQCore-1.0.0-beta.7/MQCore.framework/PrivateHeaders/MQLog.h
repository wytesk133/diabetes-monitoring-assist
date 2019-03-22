
#ifdef DEBUG
  #define MQLog(s,...) \
    NSLog((s), ##__VA_ARGS__);
#else
  #define MQLog(s,...) \
    ((void)0)
#endif