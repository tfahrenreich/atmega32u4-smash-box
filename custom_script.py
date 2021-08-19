Import("env")
board_config = env.BoardConfig()

board_config.update("build.hwids", [
    ["0x2341", "0x0036"],
    ["0x0f0d", "0x0092"],
    ["0x2A03", "0x0036"],
    ["0x2A03", "0x8036"]
])