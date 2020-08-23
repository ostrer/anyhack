# Any(Connect)Hack
This code adds interception library to a CISCO AnyConnect client
Library replaces a method `CInterfaceRouteMonitorLinux::routeCallbackHandler()` with a dummy function.
As result AnyConnect will not redirect the LAN route back to a cisco tun interface.
Installation will add `LD_LIBRARY_PRELOAD` to a `vpnagentd`. After package installation finished, please re-establish VPN connection.
When AnyConnect established the connection in order to allow "LAN" access just execute an `sudo anyhack` script.
To restore the policies - reconnect VPN.
