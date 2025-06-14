
// VCC-GND YD-2040
// USR LED  GP25
// USR KEY  GP24
// WS2812   GP23

// JP1 -> GP7 GP8
// high (bridged) -> left
#define SPLIT_HAND_PIN GP8
#define SPLIT_HAND_PIN_ GP7

#define HAVE_PS2_PIN GP15
#define HAVE_PS2_PIN_ GP14

#define PS2_RST_PIN GP10

#define USR_LED_PIN GP25

//#define MASTER_RIGHT
#define SPLIT_USB_DETECT
#define SPLIT_LAYER_STATE_ENABLE

// serial connection, PIO0
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP16
#define SERIAL_USART_RX_PIN GP17
#define SERIAL_USART_PIN_SWAP

// trackpoint, PIO1
#define PS2_PIO_USE_PIO1
//#define PS2_MOUSE_DEBUG_RAW
#define PS2_MOUSE_DEBUG_HID

// indicator led
#define WS2812_DI_PIN GP23
#define RGBLIGHT_LED_COUNT 1
#define RGBLIGHT_SPLIT
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_DEFAULT_VAL 32
#define RGBLIGHT_LIMIT_VAL 32

