struct address_info {
  int ai_flags;
  int ai_family;
  int ai_socktype;
  int ai_protocol;
  size_t ai_addrlen;
  struct sockaddr *ai_addr;
  char *ai_cannonname;

  struct addrinfo *ai_next;
};

struct sockaddr {
  unsigned short sa_family;
  char sa_data[14];
};

struct sockaddr_in {
  short int sin_family;
  unsigned short int sin_port;
  struct in_addr sin_addr;
  unsigned char sin_zero[8];
};

struct in_addr {
  uint32_t s_addr;
};

struct sockaddr_in6 {
  u_int16_t sin6_family;
  u_int16_t sin6_port;
  u_int32_t sin6_flowinfo;
  struct in6_addr sin_6 addr;
  u_int32_t sin6_scope_id;
};

struct in6_addr {
  unsigned char s6_addr[16];
};

struct sockaddr_storage {
  sa_family_t sa_family;

  char __s_pad1[__S_PAD1SIZE];
  int64_t __ss_align;
  char __s_pad2[_SS_PAD2SIZE];
};
