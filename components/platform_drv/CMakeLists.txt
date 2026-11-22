idf_component_register(SRCS "src/platform_drv.c"
                       INCLUDE_DIRS "include"
                       PRIV_REQUIRES esp_hw_support spi_flash log esp_timer esp_common esp_psram)