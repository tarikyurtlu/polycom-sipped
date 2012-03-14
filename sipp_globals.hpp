/*
 * sipp_globals.hpp
 *
 *
 *  Created on: Mar 9, 2012
 *      Author: rlum
 */

#ifndef SIPP_GLOBALS_HPP_
#define SIPP_GLOBALS_HPP_

/* Std C includes */
#ifdef WIN32
  #include <time.h>
  #include <windows.h>
  #include <winsock2.h>
  #include <ws2tcpip.h>
#else
  #include <sys/socket.h>     // sockaddr_storage
#endif


#include <list>
#include <map>
#include <set>
#include <string>

#include "infile.hpp"   // FileContents
#include "variables.hpp" // VariableTable

#ifdef _USE_OPENSSL
#include "sslcommon.hpp"  // BIO, SSL
#endif


#define T_UDP                      0
#define T_TCP                      1
#define T_TLS                      2

#ifdef _USE_OPENSSL
#define DEFAULT_TLS_CERT           ((char *)"cacert.pem")
#define DEFAULT_TLS_KEY            ((char *)"cakey.pem")
#define DEFAULT_TLS_CRL            ((char *)"")
#endif

#define TRANSPORT_TO_STRING(p)     ((p==T_TCP) ? "TCP" : ((p==T_TLS)? "TLS" :"UDP"))

#define SIPP_MAXFDS                65536
#define SIPP_MAX_MSG_SIZE          65536

#define MSG_RETRANS_FIRST          0
#define MSG_RETRANS_RETRANSMISSION 1
#define MSG_RETRANS_NEVER          2

#define DISPLAY_STAT_SCREEN        1
#define DISPLAY_REPARTITION_SCREEN 2
#define DISPLAY_SCENARIO_SCREEN    3
#define DISPLAY_VARIABLE_SCREEN    4
#define DISPLAY_TDM_MAP_SCREEN     5
#define DISPLAY_SECONDARY_REPARTITION_SCREEN 6

#define MAX_RECV_LOOPS_PER_CYCLE   1000
#define MAX_SCHED_LOOPS_PER_CYCLE  1000
#define NB_UPDATE_PER_CYCLE        1

#define MAX_PEER_SIZE              4096  /* 3pcc extended mode: max size of peer names */
#define MAX_LOCAL_TWIN_SOCKETS     10    /*3pcc extended mode:max number of peers from which
                                           cmd messages are received */

/******************** Default parameters ***********************/

#define DEFAULT_RATE                 10.0
#define DEFAULT_RATE_SCALE           1.0
#define DEFAULT_RATE_PERIOD_MS       1000
#define DEFAULT_TRANSPORT            T_UDP
#define DEFAULT_PORT                 5060
#define DEFAULT_MEDIA_PORT           6000
#define DEFAULT_3PCC_PORT            6060
#define DEFAULT_SERVICE              ((char *)"service")
#define DEFAULT_AUTH_PASSWORD        ((char *)"password")
#define DEFAULT_REPORT_FREQ          1000
#define DEFAULT_REPORT_FREQ_DUMP_LOG 60000
#define DEFAULT_TIMER_RESOLUTION     1
#define DEFAULT_FREQ_DUMP_RTT        200
#define DEFAULT_MAX_MULTI_SOCKET     50000
#define DEFAULT_CTRL_SOCKET_PORT     8888
#define DEFAULT_DEADCALL_WAIT      33000

#define DEFAULT_BEHAVIOR_NONE      0
#define DEFAULT_BEHAVIOR_BYE       1
#define DEFAULT_BEHAVIOR_ABORTUNEXP  2
#define DEFAULT_BEHAVIOR_PINGREPLY   4

#define DEFAULT_BEHAVIOR_ALL       (DEFAULT_BEHAVIOR_BYE | DEFAULT_BEHAVIOR_ABORTUNEXP | DEFAULT_BEHAVIOR_PINGREPLY)

extern int                duration;
extern double             rate;
extern double             rate_scale;         // sipp only
extern int                rate_increase;
extern int                rate_max;
extern bool               rate_quit;
extern int                users;
extern int                rate_period_ms;
extern int                sleeptime;          // sipp only
extern unsigned long      defl_recv_timeout;
extern unsigned long      defl_send_timeout;
extern unsigned long      global_timeout;     // sipp only
extern int                transport;
extern bool               retrans_enabled;

//call.hpp defines constants that these initialize to
extern int                rtcheck;
extern int                max_udp_retrans;
extern int                max_invite_retrans;
extern int                max_non_invite_retrans;

extern unsigned long      default_behaviors;
extern unsigned long      deadcall_wait;
extern bool               pause_msg_ign;
extern bool               auto_answer;
extern int                multisocket;
extern int                compression;
extern int                peripsocket;
extern int                peripfield;
extern bool               bind_local;
extern void              *monosocket_comp_state;
extern char              *service;
extern char              *auth_password;
extern unsigned long      report_freq;
extern unsigned long      report_freq_dumpLog;
extern bool               periodic_rtd;
extern const char        *stat_delimiter;

extern bool               timeout_exit;
extern bool               timeout_error;

extern unsigned long      report_freq_dumpRtt;

extern int      max_multi_socket;
extern bool     skip_rlimit;

extern unsigned int       timer_resolution;
extern int                max_recv_loops;
extern int                max_sched_loops;

extern unsigned int       global_t2;
extern unsigned int       auto_answer_expires;

extern char               local_ip[];
extern char               local_ip_escaped[];
extern bool               local_ip_is_ipv6;
extern int                local_port;
extern char               control_ip[];
extern int                control_port;
extern int                buff_size;
extern int                tcp_readsize;
#ifdef PCAPPLAY
extern int                hasMedia;
#endif
extern bool               rtp_echo_enabled;
extern char               media_ip[];
extern char               media_ip_escaped[];
extern int                user_media_port;
extern int                media_port;
extern size_t             media_bufsize;
extern bool               media_ip_is_ipv6;
extern char               remote_ip[];
extern char               remote_ip_escaped[];
extern int                remote_port;
extern unsigned int       pid;
extern bool               print_all_responses;
extern unsigned long      stop_after;
extern int                quitting;
extern bool               q_pressed;
extern int                interrupt;
extern bool               paused;
extern int                lose_packets;
extern double             global_lost;
extern char               remote_host[];
extern char               twinSippHost[];
extern char               twinSippIp[];
extern char              *master_name;
extern char              *slave_number;
extern int                twinSippPort;
extern bool               twinSippMode;
extern bool               extendedTwinSippMode;

extern bool               nostdin;
extern bool               backgroundMode;
extern bool               signalDump;

extern int                currentScreenToDisplay;
extern int                currentRepartitionToDisplay;
extern unsigned int       base_cseq;
extern char              *auth_uri;
extern const char        *call_id_string;
extern char             **generic[100]; // sipp:4673  sizeof(generic[0] complains error: invalid application of ‘sizeof’ to incomplete type ‘char** []’ without the size of the array here...mem alloc here?
extern bool               no_call_id_check;
extern int                dump_xml;
extern int                dump_sequence_diagram;

extern bool               force_client_mode;
extern bool               force_server_mode;

/* TDM map */
extern bool               use_tdmmap;
extern unsigned int       tdm_map_a;
extern unsigned int       tdm_map_b;
extern unsigned int       tdm_map_c;
extern unsigned int       tdm_map_x;
extern unsigned int       tdm_map_y;
extern unsigned int       tdm_map_z;
extern unsigned int       tdm_map_h;
extern bool               tdm_map[1024];

#ifdef _USE_OPENSSL
extern BIO               *twinSipp_bio ;
extern SSL               *twinSipp_ssl ;
extern char              *tls_cert_name;
extern char              *tls_key_name;
extern char              *tls_crl_name;
#endif

// extern field file management
typedef std::map<std::string, FileContents *> file_map;
extern file_map           inFiles;
typedef std::map<std::string, str_int_map *> file_index;
extern char*              ip_file;
extern char*              default_file;

// free user id list
extern std::list<int>     freeUsers;
extern std::list<int>     retiredUsers;
extern AllocVariableTable *globalVariables;
extern AllocVariableTable *userVariables;
typedef std::map<int, VariableTable *> int_vt_map;
extern int_vt_map          userVarMap;

//extern int      new_socket(bool P_use_ipv6, int P_type_socket, int * P_status);
struct   sipp_socket      *new_sipp_socket(bool use_ipv6, int transport);
struct sipp_socket        *new_sipp_call_socket(bool use_ipv6, int transport, bool *existing);
struct sipp_socket        *sipp_accept_socket(struct sipp_socket *accept_socket, struct sockaddr_storage *source=0);
int                        sipp_bind_socket(struct sipp_socket *socket, struct sockaddr_storage *saddr, int *port);
int                        sipp_connect_socket(struct sipp_socket *socket, struct sockaddr_storage *dest);
int                        sipp_reconnect_socket(struct sipp_socket *socket);
void                       sipp_customize_socket(struct sipp_socket *socket);
int                        delete_socket(int P_socket);
extern int                 min_socket;
extern int                 select_socket;
extern bool                socket_close;
extern bool                test_socket;
extern bool                maxSocketPresent;

unsigned long              getmilliseconds();
unsigned long long         getmicroseconds();

/************************ Statistics **************************/

extern unsigned long       last_report_calls;
extern unsigned long       nb_net_send_errors;
extern unsigned long       nb_net_cong;
extern unsigned long       nb_net_recv_errors;
extern bool                cpu_max;
extern bool                outbound_congestion;
extern int                 open_calls_user_setting;
extern int                 resynch_send;
extern int                 resynch_recv;
extern unsigned long       rtp_pckts;
extern unsigned long       rtp_bytes;
extern unsigned long       rtp_pckts_pcap;
extern unsigned long       rtp_bytes_pcap;
extern unsigned long       rtp2_pckts;
extern unsigned long       rtp2_bytes;
extern unsigned long       rtp2_pckts_pcap;
extern unsigned long       rtp2_bytes_pcap;

/************* Rate Control & Contexts variables **************/

extern int                 last_running_calls;
extern int                 last_woken_calls;
extern int                 last_paused_calls;
extern unsigned int        open_calls_allowed;
extern unsigned long       last_report_time;
extern unsigned long       last_dump_time;

/********************** Clock variables ***********************/

extern unsigned long       clock_tick;
extern unsigned long       scheduling_loops;
extern unsigned long       last_timer_cycle;

extern unsigned long       watchdog_interval;
extern unsigned long       watchdog_minor_threshold;
extern unsigned long       watchdog_minor_maxtriggers;
extern unsigned long       watchdog_major_threshold;
extern unsigned long       watchdog_major_maxtriggers;
extern unsigned long       watchdog_reset;


/********************* dynamic Id ************************* */
extern  int                maxDynamicId;  // max value for dynamicId; this value is reached
extern  int                startDynamicId;  // offset for first dynamicId  FIXME:in CmdLine
extern  int                stepDynamicId;      // step of increment for dynamicId


#define GET_TIME(clock)       \
{                             \
  struct timezone tzp;        \
  gettimeofday (clock, &tzp); \
}

/*********************** Global Sockets  **********************/

extern struct sipp_socket *main_socket;
extern struct sipp_socket *main_remote_socket;
extern struct sipp_socket *tcp_multiplex;
extern int                 media_socket;
extern int                 media_socket_video;

extern struct sockaddr_storage local_sockaddr;
extern struct sockaddr_storage localTwin_sockaddr;
extern int                 user_port;
extern char                hostname[];  // TODO: EXTERN ARRAY BAD??
extern bool                is_ipv6;

extern int                 reset_number;
extern bool                reset_close;
extern int                 reset_sleep;
extern bool                sendbuffer_warn;
/* A list of sockets pending reset. */
extern std::set<struct sipp_socket *> sockets_pending_reset;

extern struct addrinfo *   local_addr_storage;

extern struct sipp_socket *twinSippSocket;
extern struct sipp_socket *localTwinSippSocket;
extern struct sockaddr_storage twinSipp_sockaddr;

/* 3pcc extended mode */
typedef struct _T_peer_infos {
  char                     peer_host[40];
  int                      peer_port;
  struct sockaddr_storage  peer_sockaddr;
  char                     peer_ip[40];
  struct sipp_socket      *peer_socket ;
  }                        T_peer_infos;

typedef std::map<std::string, char * > peer_addr_map;
extern peer_addr_map       peer_addrs;
typedef std::map<std::string, T_peer_infos> peer_map;
extern peer_map            peers;
typedef std::map<struct sipp_socket *, std::string > peer_socket_map;
extern peer_socket_map     peer_sockets;
extern struct sipp_socket *local_sockets[MAX_LOCAL_TWIN_SOCKETS];
extern int                 local_nb;
extern int                 peers_connected;

extern struct sockaddr_storage remote_sockaddr;
extern short               use_remote_sending_addr;
extern struct sockaddr_storage remote_sending_sockaddr;

enum E_Alter_YesNo
  {
    E_ALTER_YES=0,
    E_ALTER_NO
  };

/************************** Trace Files ***********************/

extern FILE *              screenf;
extern FILE *              countf;
// extern FILE * timeoutf;
extern bool                useMessagef;
extern bool                useCallDebugf;
extern bool                useShortMessagef;
extern bool                useScreenf;
extern bool                useLogf;
extern bool                useDebugf;
extern bool                useExecf;
//extern bool   useTimeoutf;
extern bool                dumpInFile;
extern bool                dumpInRtt;
extern bool                useCountf;
extern char               *scenario_file;
extern char               *slave_cfg_file;

extern char                screen_last_error[];

void                       rotate_errorf();
int                        rotatef(struct logfile_info *lfi);
void                       log_off(struct logfile_info *lfi);

/* Screen/Statistics Printing Functions. */
void                       print_statistics(int last);
void                       print_count_file(FILE *f, int header);


/********************* Mini-Parser Routines *******************/

int                        get_method(char *msg);
char                      *get_tag_from_to(char *msg);
char                      *get_tag_from_from(char *msg);
unsigned long int          get_cseq_value(const char *msg);
unsigned long              get_reply_code(const char *msg);

/********************** Network Interfaces ********************/

int                        send_message(int s, void ** comp_state, char * msg);
#ifdef _USE_OPENSSL
int                        send_message_tls(SSL *s, void ** comp_state, char * msg);
#endif

/* Socket Buffer Management. */
#define NO_COPY 0
#define DO_COPY 1
struct socketbuf          *alloc_socketbuf(char *buffer, size_t size, int copy);
void                       free_socketbuf(struct socketbuf *socketbuf);

/* These buffers lets us read past the end of the message, and then split it if
 * required.  This eliminates the need for reading a message octet by octet and
 * performing a second read for the content length. */
struct socketbuf {
  char                     *buf;
  size_t                    len;
  size_t                    offset;
  struct sockaddr_storage   addr;
  struct socketbuf         *next;
};

/* This is an abstraction of a socket, which provides buffers for input and
 * output. */
struct sipp_socket {
  int                        ss_count; /* How many users are there of this socket? */

  int                        ss_transport; /* T_TCP, T_UDP, or T_TLS. */
  bool                       ss_ipv6;
  bool                       ss_control; /* Is this a control socket? */
  bool                       ss_call_socket; /* Is this a call socket? */
  bool                       ss_changed_dest; /* Has the destination changed from default. */

  int                        ss_fd;  /* The underlying file descriptor for this socket. */
  void                      *ss_comp_state; /* The compression state. */
#ifdef _USE_OPENSSL
  SSL                       *ss_ssl;  /* The underlying SSL descriptor for this socket. */
  BIO                       *ss_bio;  /* The underlying BIO descriptor for this socket. */
#endif
  struct sockaddr_storage    ss_remote_sockaddr; /* Who we are talking to. */
  struct sockaddr_storage    ss_dest; /* Who we are talking to. */


  int                        ss_pollidx; /* The index of this socket in our poll structures. */
  bool                       ss_congested; /* Is this socket congested? */
  bool                       ss_invalid; /* Has this socket been closed remotely? */

  struct socketbuf          *ss_in; /* Buffered input. */
  size_t                     ss_msglen; /* Is there a complete SIP message waiting, and if so how big? */
  struct socketbuf          *ss_out; /* Buffered output. */
};

/* Write data to a socket. */
int                          write_socket(struct sipp_socket *socket, char *buffer, ssize_t len, int flags, struct sockaddr_storage *dest);
/* Mark a socket as "bad". */
void                         sipp_socket_invalidate(struct sipp_socket *socket);
/* Actually free the socket. */
void                         sipp_close_socket(struct sipp_socket *socket);

#define WS_EAGAIN 1 /* Return EAGAIN if there is no room for writing the message. */
#define WS_BUFFER 2 /* Buffer the message if there is no room for writing the message. */


#if defined (__hpux) || defined (__alpha) && !defined (__FreeBSD__)
#define sipp_socklen_t  int
#else
#define sipp_socklen_t  socklen_t
#endif

#define SOCK_ADDR_SIZE(a) \
  (((a)->ss_family == AF_INET) ? sizeof(struct sockaddr_in) \
                               : sizeof(struct sockaddr_in6))

#if defined(__cplusplus) && defined (__hpux)
#define _RCAST(type, val) (reinterpret_cast<type> (val))
#else
#define _RCAST(type, val) ((type)(val))
#endif

/********************* Utilities functions  *******************/

char                      *strcasestr2 ( const char *__haystack, const char *__needle);
char                      *get_peer_addr(char *);
int                        get_decimal_from_hex(char hex);

bool                       reconnect_allowed();
void                       reset_connection(struct sipp_socket *);
void                       close_calls(struct sipp_socket *);
int                        close_connections();
int                        open_connections();
void                       timeout_alarm(int);

int                        determine_remote_and_local_ip();

char                      *jump_over_timestamp(char *src);

/* extended 3PCC mode */
struct sipp_socket       **get_peer_socket(char *);
bool                       is_a_peer_socket(struct sipp_socket *);
bool                       is_a_local_socket(struct sipp_socket *);
void                       connect_to_peer (char *, int , sockaddr_storage *, char *, struct sipp_socket **);
void                       connect_to_all_peers ();
void                       connect_local_twin_socket(char *);
void                       close_peer_sockets();
void                       close_local_sockets();
void                       free_peer_addr_map();

/******************** Recv Poll Processing *********************/

extern struct sipp_socket  *sockets[SIPP_MAXFDS];


/************************** Constants **************************/

#ifdef SVN_VERSION
# ifdef LOCAL_VERSION_EXTRA
#  define SIPP_VERSION               SVN_VERSION LOCAL_VERSION_EXTRA
# else
#  define SIPP_VERSION               SVN_VERSION
# endif
#else
# define SIPP_VERSION               "unknown"
#endif



#endif /* SIPP_GLOBALS_HPP_ */
