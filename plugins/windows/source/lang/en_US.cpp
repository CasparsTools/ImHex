#include <hex/api/content_registry.hpp>
#include <hex/helpers/lang.hpp>

namespace hex::plugin::windows {

    void registerLanguageEnUS() {
        ContentRegistry::Language::addLocalizations("en-US", {
            { "hex.windows.view.tty_console.name", "TTY Console" },
                { "hex.windows.view.tty_console.config", "Configuration"},
                    { "hex.windows.view.tty_console.port", "Port" },
                    { "hex.windows.view.tty_console.reload", "Reload" },
                    { "hex.windows.view.tty_console.baud", "Baud rate" },
                    { "hex.windows.view.tty_console.num_bits", "Data bits" },
                    { "hex.windows.view.tty_console.stop_bits", "Stop bits" },
                    { "hex.windows.view.tty_console.parity_bits", "Parity bit" },
                    { "hex.windows.view.tty_console.cts", "Use CTS flow control" },
                    { "hex.windows.view.tty_console.connect", "Connect" },
                    { "hex.windows.view.tty_console.disconnect", "Disconnect" },
                    { "hex.windows.view.tty_console.connect_error", "Failed to connect to COM Port!" },
                    { "hex.windows.view.tty_console.no_available_port", "No valid COM port is selected or no COM port is available!" },
                    { "hex.windows.view.tty_console.clear", "Clear" },
                    { "hex.windows.view.tty_console.auto_scroll", "Auto scroll" },
                { "hex.windows.view.tty_console.console", "Console" },
                    { "hex.windows.view.tty_console.send_etx", "Send ETX" },
                    { "hex.windows.view.tty_console.send_eot", "Send EOT" },
                    { "hex.windows.view.tty_console.send_sub", "Send SUB" },

                    { "hex.builtin.setting.general.context_menu_entry", "Windows context menu entry" },
        });
    }

}