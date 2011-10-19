if [ "_$1" = "_-n" ]; then
    sh $0 |tr '\n' '$' |sed 's/\$/\\n/g';
    exit;
    fi

if [ "_$1" = "_-BUILD" ]; then
    BUILD="$(cat .build 2>/dev/null)";
    N_BUILD=$(expr ${BUILD} + 1);
    echo -n "${N_BUILD}" > .build; 
    echo -n "${N_BUILD}";
    exit;
    fi;

if [ "_$1" = "_-VERSION" ]; then
    VERSION="$(cat .version 2>/dev/null)";
    echo -n "${VERSION}";
    exit;
    fi;

LC_ALL=""
LANG=""
[ "_`git rev-parse --git-dir 2>/dev/null`" != "_" ];
GIT=$?
echo -n 'user:       '
whoami
echo -n 'hostname:   '
hostname
[ $GIT -eq 0 ] && echo -n 'branch:     '
[ $GIT -eq 0 ] && git branch |grep '*' |sed 's/*//g;s/ //g' |tr -d '\n' #branch name
[ $GIT -eq 0 ] && git status |grep -q modified 2>/dev/null && /bin/echo -n ' (changed)' #is changed?
echo
echo -n 'local date: '
date
[ $GIT -eq 0 ] && echo "commit info:"
[ $GIT -eq 0 ] && PAGER="" git log -1 --pretty="branch:    %d%ncommit:     %H%nauthor:     %an <%ae>%ndate:       %ai"

