#include <sys/socket.h>
#include <linux/netlink.h>

int _ZN27CInterfaceRouteMonitorLinux20routeCallbackHandlerEv()
{
  int fd=50;          // max fd to try
  char buf[8192];
  struct sockaddr_nl sa;
  socklen_t len = sizeof(sa);

  while (fd) {
     if (!getsockname(fd, (struct sockaddr *)&sa, &len)) {
        if (sa.nl_family == AF_NETLINK) {
           ssize_t n = recv(fd, buf, sizeof(buf), MSG_DONTWAIT);
        }
     }
     fd--;
  }
  return 0;
}
