#ifndef gbra_h
#define gbra_h

#include "WiFi.h"
#include "wifi_provisioning/manager.h"

typedef enum {
    WIFI_PROV_SCHEME_SOFTAP,
#if CONFIG_BLUEDROID_ENABLED
    WIFI_PROV_SCHEME_BLE,
#endif
    WIFI_PROV_SCHEME_MAX
} prov_scheme_t;

typedef enum {
    WIFI_PROV_SCHEME_HANDLER_NONE,
#if CONFIG_BLUEDROID_ENABLED
    WIFI_PROV_SCHEME_HANDLER_FREE_BTDM,
    WIFI_PROV_SCHEME_HANDLER_FREE_BLE,
    WIFI_PROV_SCHEME_HANDLER_FREE_BT,
#endif
    WIFI_PROV_SCHEME_HANDLER_MAX
} scheme_handler_t;

class WiFiProvClass
{  
    public:

        void beginProvision(prov_scheme_t prov_scheme = WIFI_PROV_SCHEME_SOFTAP, scheme_handler_t scheme_handler = WIFI_PROV_SCHEME_HANDLER_NONE,
        		wifi_prov_security_t security = WIFI_PROV_SECURITY_1, const char * pop = "abcd1234", const char * service_name = NULL, const char * service_key = NULL, uint8_t *uuid = NULL);
};

extern WiFiProvClass WiFiProv;

#endif