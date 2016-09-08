#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

#define BACKLOG 10     // how many pending connections queue will hold

//#define PORT 4950
#define BUFSIZE 1000
int play =0;
char mssg_type[23];
char mssg_type1[3];
char mssg_type2[20];
char *word,*rword,*srword;
int counter=0;
int maxattempts;

void func_sword(char rword[],char srword[])
{
int rlen=strlen(rword);
int rx,ry;int rz=0;
for(rx=rlen;rx>0;rx--)
 {  int r1=rand()%rx;
   srword[rz]=rword[r1];
srword[rz+1]='\0'; 
   rz++; 
   for(ry=r1; ry<rx;ry++)
     { 
//printf("rx=%d,ry=%d,%s,%s\n",rx,ry, rword,srword);
rword[ry]=rword[ry+1];
     }
 }
}


void func_rword()
{
int wordcount = 1162, i;

    char *words[] = {"abacus","abate","abdication","aberration","abet","abeyance","abhor","abide","abjure","abraded","abrogate","abscond","abstruse","abut","abysmal","acarpous","acclaimed","accolade","accretion","adamant","admonitory","adorn","adulteration","affable","affinity","aggravate","agile","agog","ail","alacrity","alcove","allegiance","alleviate","alloy","aloof","amalgamate","ambidextrous","ambiguous","ambivalent","ameliorate","amortize","anguish","animosity","antidote","antithetical","apartheid","aplomb","apostate","apotheosis","appease","apprehensive","apprise","approbation","apropos","apt","arabesque","arboreal","ardor","arduous","argot","arrant","arrogance","articulate","ascend","ascertain","ascetic","ascribe","aseptic","asperity","aspersion","assail","assiduous","assuage","asterisk","astringent","astute","atonement","attenuate","attune","audacious","augury","august","auspicious","austere","auxiliary","aver","aversion","avid","avow","baleful","balk","baneful","barrage","barren","bask","beatify","bedizen","belabor","bellicose","belligerent","benefactor","benevolence","benign","bequest","berate","bereft","bewilder","bigot","bilge","blandishment","blandness","blatant","blithe","bogus","boisterous","bolster","boorish","brash","brass","brazen","breach","brittle","broach","brook","buoyant","burgeon","burnish","cabal","cadge","cajole","calipers","calumny","candid","cant","cantankerous","canvass","castigate","castigation","catalyst","caustic","censure","centurion","chary","chastened","chastisement","chauvinist","chicanery","chisel","churl","clamor","clientele","clinch","cling","clot","cloture","coagulation","coalescing","coax","coda","coddle","coerce","coeval","cogent","cogitate","cognizant","colander","collusion","combustion","commemorate","commodious","commuter","complaisance","compunction","conceal","conceit","conciliatory","concord","concur","condense","condone","congeal","conjoin","connoisseur","connotation","consequential","console","conspicuous","consternation","constrain","constrict","consume","consummate","contemn","contentious","contiguous","contrite","contumacious","conundrum","conviction","convoke","convoluted","cordial","cordon","cornucopia","corporeal","correlate","corroboration","countenance","counterfeit","countervail","covert","covetous","cower","coy","crass","cravat","craven","crease","credulity","credulous","crush","cryptic","cumbersome","curmudgeon","curriculum","cursory","curtail","dainty","daunt","dawdler","dearth","debacle","decorum","decree","decry","defer","deferential","defiance","delineate","deluge","demagogue","demur","denigrate","denouement","deplete","deposition","deprave","deprecate","dereliction","derision","derivative","derogatory","descry","desiccant","desuetude","desultory","deter","detraction","detumescence","deviance","dexterity","diaphanous","diatribe","diffidence","dilate","disallow","discern","discomfit","disconcert","discountenance","discourse","discredit","discreet","discrete","disdain","disencumber","disheveled","disingenuous","disinter","dislodge","dismal","disparate","disproof","dissemble","disseminate","dissent","dissolution","distraught","divergence","divestiture","divulge","doggerel","dogmatic","dolt","dormant","dote","drawl","droll","drone","drowsiness","dubious","dud","dulcet","dupe","duplicity","duress","dwarf","dynamo","earthenware","ebullience","ebullient","ecumenical","edacious","eddy","edible","effete","efficacy","effluvia","effrontery","egress","elaborate","elegy","elicit","eloquence","emaciate","embellish","embezzle","emote","empirical","encapsulate","encomium","encumbrance","endearing","endemic","endorse","enduring","enervate","engender","engrave","engrossing","engulf","enigma","enmity","ensign","entangle","enthral","entice","entreat","enunciate","enzyme","epicurean","epistle","epithet","epitome","equable","equanimity","equilibrium","equipoise","equivocal","equivocate","eradicate","erratic","erudite","eschew","esoteric","espouse","eulogy","euphoria","euthanasia","evasive","evince","evoke","excoriation","exculpate","exhaustive","exigency","exoneration","exorbitant","expatiate","expedient","expiation","exploit","expostulate","expurgate","exscind","extant","extempore","extenuate","extinct","extinguish","extirpate","extol","extort","extralegal","extricable","extrovert","exuberance","facetious","facile","fallacious","falter","fatuous","fawn","feckless","fecund","feint","felicitous","felon","ferment","ferocity","ferret","fervid","fervor","fetid","fetter","feud","fidelity","fidget","figurehead","finesse","finical","finicky","fission","fixate","flak","flamboyant","flaunting","flax","fledged","fleet","flinch","flop","florid","flout","fluke","fluster","foible","foil","foment","foolproof","foppish","forage","forbear","forbearance","ford","forestall","forfeit","forge","forgery","forswear","foster","fracas","fragile","fragrant","frantic","frenetic","fret","fringe","froward","frugal","fulmination","fulsome","gainsay","garble","garment","garner","garrulity","garrulous","gaucherie","germane","gist","glean","glib","glimmer","gloat","glut","gnaw","goad","gorge","gossamer","gouge","grandiloquent","grave","graze","gregarious","grievous","grovel","guile","gullible","gush","gust","hack","halcyon","hallow","harangue","harbinger","harrow","haughty","heed","heinous","heresy","hermetic","heterogeneous","hew","highbrow","hirsute","hoax","hoi","hollow","holster","homiletics","hone","hoodwink","hospitable","hubris","hush","husk","hypocrisy","iconoclast","idiosyncrasy","idolatry","idyll","ignoble","ignominious","illicit","imbroglio","immaculate","imminent","immutable","impair","impassive","impecunious","impede","impediment","impending","imperative","imperious","impermeable","imperturbable","impervious","imperviousness","impetuous","impiety","implacable","implicate","implicit","implosion","importune","imprecation","impromptu","impudent","impugned","impute","inadvertent","inane","inasmuch","incense","incessant","inchoate","incipient","incise","incite","inclined","incongruous","incorrigibility","incredulous","inculcate","incumbents","incursion","indefatigability","indelible","indigence","indigenous","indistinct","indolence","indomitable","indulge","indulgent","ineffable","ineluctable","inept","ineptitude","inferno","infuriate","infuse","ingenuous","ingest","inimical","inimitable","innocuous","inscrutable","insensible","insinuate","insipid","insouciant","insularity","insurrection","interdict","interim","intersperse","intransigence","intransigent","intrepid","introspection","inundate","inured","invective","inveigh","inveterate","invincible","involute","irascible","irate","ire","irksome","irresolute","irrevocable","itinerate","jabber","jibe","jocular","judicious","knit","labyrinthine","lachrymose","lackluster","lament","lassitude","latent","laudatory","lavish","legacy","levee","levity","libel","liberality","libertine","lien","limn","limp","lionize","lithe","loll","lope","loquacious","lucubrate","luculent","lugubrious","lull","lumber","luminary","lurk","lustrous","macabre","macerate","machination","maladroit","malapropism","malevolence","malign","malinger","malleable","manacle","massacre","matriculation","maudlin","maul","maverick","mellifluous","mendacity","mendicant","mercurial","meretricious","mesmerize","meticulous","mettle","mettlesome","middling","minatory","mince","misanthrope","mischievous","miser","misogynist","moderation","mollify","molt","morbid","morose","muffler","multifarious","mundane","myriad","nadir","nascent","nebulous","negligent","neophyte","nexus","nibble","noisome","nonchalant","nonplused","nostrum","noxious","nugatory","obdurate","obfuscate","oblivious","obloquy","obsequious","obstreperous","obtain","obtrusive","obtuse","obviate","occluded","odious","odium","odor","officious","ominous","onerous","opaqueness","opprobrious","ossify","ostensible","ostentation","ostracism","overhaul","overweening","paean","palate","palatial","palliate","palpability","palpitate","panegyric","paradigm","parenthesis","pariah","parsimonious","partisan","patron","paucity","peccadillo","pedantic","pedestrian","pellucid","penchant","penitent","penurious","penury","peregrination","peremptory","perfidious","perfidy","perfunctory","perilous","peripatetic","perish","perjury","permeate","pernicious","perpetrate","personable","perspicacity","pertain","pest","petrified","petrify","petrous","petulant","philistine","phlegmatic","picaresque","pied","pinch","pine","pious","piquant","pique","pitfall","pith","pivotal","placate","plaintive","plaque","platitude","plea","plead","plethora","pliant","plod","pluck","plumb","plummet","plunge","poignant","poncho","ponderous","portent","precarious","precepts","preclude","precursory","predilection","predominate","preen","premature","preponderance","presage","presumption","preternatural","prevalent","prevaricate","prim","pristine","probity","proclivity","procrastination","prodigal","prodigious","profane","profligacy","profligate","profundity","profuse","proliferate","prolix","prone","propagation","propinquity","propitiatory","propitious","prosaic","proscribe","protracted","provident","provisional","provoke","prudence","prudish","prune","pry","pucker","pugnacious","puissance","punctilious","pundit","pungency","purvey","pusillanimous","putrefaction","pyre","quack","quaff","quail","qualm","quandary","quell","quibble","quiescence","quiescent","quirk","quixotic","quotidian","rabble","raconteur","raffish","ramify","rancorous","rant","rapacious","rarefy","rave","reactionary","rebuff","recalcitrant","recant","recast","recidivism","reciprocity","recitals","recluse","recompense","reconcile","recondite","recreancy","recuperate","redeem","redoubtable","refine","refractory","refulgent","regale","regicide","reiterate","rejuvenation","relapse","remonstrate","render","renovate","renowned","repast","repel","repine","reproach","reprobate","repudiate","repulsive","requite","rescind","resigned","resilience","resort","restive","resuscitation","retard","reticent","revere","reverent","riddle","rift","rivet","roll","rotund","ruffian","rumple","sagacious","salacious","salubrious","salutary","sanctimony","sanction","sanguine","sanity","sash","satiate","saturnine","savant","savor","sawdust","scabbard","scent","scorch","scribble","scurvy","secular","sedulous","seminal","sententious","sequence","sere","sermon","serrated","serration","servile","sever","severance","shallow","shard","sheath","shrewd","shrill","shun","shunt","sidestep","simper","sinuous","skiff","skit","slack","slake","slate","sluggard","slur","smolder","snare","snub","soar","sober","sobriety","sodden","soggy","solvent","somatic","soot","sophisticated","sophistry","sophomoric","soporific","sordid","spear","specious","splenetic","splice","sponge","spurious","spurn","squalid","squander","squat","stanch","steeply","stentorian","stickler","stigma","stigmatize","sting","stingy","stint","stipple","stipulate","stolid","stray","streak","striated","stride","strut","stygian","stymie","subdue","sublime","submerge","suborn","subpoena","substantiation","subsume","succor","suffice","suffocate","sullied","summarily","sumptuous","sundry","supercilious","superfluous","superimpose","supersede","supine","suppliant","supplicate","suppress","surcharge","surfeit","susceptibility","swerve","sycophant","synopsis","taciturn","tadpole","talon","tamp","tamper","tangential","tarnished","tassel","taunt","taut","tautology","tawdry","teetotal","temerity","temperance","temperate","tenacity","tenuous","tepid","terse","testiness","thrift","thwart","timid","timorous","toady","tonic","topple","torment","torpid","torque","tortuous","tout","tractable","transgress","transient","transitory","travesty","trenchant","trepidation","trickle","trifling","trite","truce","truculence","trudge","turbid","turbulence","turgid","turmoil","turpitude","turquoise","tyro","ubiquitous","ulterior","umbrage","uncouth","underbid","undermine","undulate","unearth","unencumbered","unfeigned","unscathed","untoward","upbraid","urbane","vacillation","vagary","vain","valiant","valorous","vanquish","veer","venal","veneer","veneration","veracity","verdant","verisimilitude","veritable","verve","vestige","vex","vigilance","vigilant","vigorous","vilify","vindictive","virago","visceral","viscous","vitiate","vituperate","vivacious","volatile","volubility","voluble","waffle","waft","wag","warmonger","warrant","wean","weigh","welter","wend","whimsical","wince","woo","writ","yarn"}
;int r = rand()%1162;
//printf("%d\n",r);
int rlen=strlen(words[r]);
word = malloc(sizeof(*word) * rlen);
rword = malloc(sizeof(*rword) * rlen);
srword = malloc(sizeof(*srword) * rlen);
strcpy(rword,words[r]);
strcpy(word,words[r]);
func_sword(rword,srword);
//printf("Words=%s\n",rword);
}








void sigchld_handler(int s)
{
    while(waitpid(-1, NULL, WNOHANG) > 0);
}


// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


//Maintaining client history #start
struct node
{
    int sokid;
    char clname[16];
    int res_cnt;
    struct node *next;
}*head;



void append(int num,char *client)
{
    struct node *temp,*right;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->sokid=num;
    temp->res_cnt=0;
    strcpy(temp->clname,client);
    right=(struct node *)head;
    while(right->next != NULL)
        right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}



void add( int num,char *cname )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->sokid=num;
    strcpy(temp->clname,cname);
    if (head== NULL)
    {
        head=temp;
        head->next=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void addafter(int num, int loc)
{
    int i;
    struct node *temp,*left,*right;
    right=head;
    for(i=1;i<loc;i++)
    {
        left=right;
        right=right->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->sokid=num;
    left->next=temp;
    left=temp;
    left->next=right;
    return;
}



void insert(int num,char * cname)
{
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        add(num,cname);
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->sokid<num)
                c++;
            temp=temp->next;
        }
        if(c==0)
            add(num,cname);
        else if(c<count())
            addafter(num,++c);
        else
            append(num,cname);
    }
}



int delete(int num)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->sokid==num)
        {
            if(temp==head)
            {
                head=temp->next;
                free(temp);
                return 1;
            }
            else
            {
                prev->next=temp->next;
                free(temp);
                return 1;
            }
        }
        else
        {
            prev=temp;
            temp= temp->next;
        }
    }
    return 0;
}

int find(char *cname)
{   struct node *temp, *prev;
    temp=head;
    if(temp==NULL)
        return 0;
    while(temp!=NULL)
    {
        if(strcmp(temp->clname,cname)==0)
            return temp->sokid;
        else
            temp=temp->next;
    }
    return 0;
}

int cnt_append(char *cname1)
{ struct node *temp, *prev;
    temp=head;
    if(temp==NULL)
        return 0;
    while(temp!=NULL)
    {
        if(strcmp(temp->clname,cname1)==0)
           {(temp->res_cnt)++;
           return (temp->res_cnt);}
        else
            temp=temp->next;
    }
 return 0;
}

void cnt_reset()
{
struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {(temp->res_cnt)=0;
      temp=temp->next;
    }

}

char *getname(int num)
{ struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->sokid==num)
        {   return temp->clname;
        }
        else
            temp=temp->next;
    }
    return NULL;
}

void display(struct node *r,int newsocket)
{
    char cl_list[]={"SCL Clients who are ONLINE now:"};
   // send(newsocket,cl_list,strlen(cl_list),0);
    r=head;
    
    // int il=strlen(cl_list);
    //cl_list[il]='\0';
static char temp_name[1000];
static int il=0;
strcpy(temp_name,cl_list);
    while(r!=NULL)
    {    il=il+strlen(r->clname);
  
        strcat(temp_name,r->clname);
        strcat(temp_name,"  ");
        int il1=il1+strlen(temp_name);        

     //   printf("Client names : %s\n",temp_name);
        r=r->next;
        if(r == NULL)
        { temp_name[strlen(cl_list)+il]='\0';
          temp_name[strlen(cl_list)+il+1]='\n';
          send(newsocket,temp_name,strlen(temp_name),0);
        }
        
        // printf("test");
        
        
    }
	
    
}


int count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
        n=n->next;
        c++;
    }
    printf("%d",c);
    return c;
}

//Maintaining client history #end

void command_parse(int argc, char *argv[], int *port,int *maxclient)
{
	if (argc != 4){
		//printf("usage : ./server -p port\n");
        printf("usage :./gserver ip port maxclients \n");
		exit(1);
	}
	else if(argc == 4){
		//if (strcmp(argv[1], "-p") == 0)
        *port = atoi(argv[2]);
        *maxclient = atoi(argv[3]);
         printf("MAX CLIENTS ALLOWED: %d\n",*maxclient);
        
        
	}
	
}

void send_to_all(int j, int i, int sockfd, int nbytes_recvd, char *recv_buf, fd_set *master)
{
	if (FD_ISSET(j, master))
    {
		//if (j != sockfd && j != i)
          if (j != sockfd)
        {
			if (send(j, recv_buf, nbytes_recvd, 0) == -1)
            {
				perror("send");
            }
        }
	}
}

void send_to_all1(int j, int i, int sockfd, int nbytes_recvd, char *recv_buf, fd_set *master)
{
	if (FD_ISSET(j, master))
    {
		 if (j != sockfd && j == i)
          //if (j != sockfd)
        {
			if (send(j, recv_buf, nbytes_recvd, 0) == -1)
            {
				perror("send");
            }
        }
	}
}




void display_leave(struct node *r,int fdmax,int j, int i, int sockfd, int nbytes_recvd, char *recv_buf, fd_set *master)
{
    r=head;
    char cl_list[]={"Updated list of ONLINE Clients : "};
    for(j = 0; j <= fdmax; j++)
        send_to_all(j, i, sockfd,strlen(cl_list), cl_list, master );
    
    
    // int il=strlen(cl_list);
    //cl_list[il]='\0';
    while(r!=NULL)
    {
        int il=strlen(r->clname);
        char cl_list1[il+2];
        strcpy(cl_list1,r->clname);
        cl_list1[il]='	';
        cl_list1[il+1]='\0';
        r=r->next;
        for(j = 0; j < fdmax+1; j++)
            send_to_all(j, i, sockfd, strlen(cl_list1), cl_list1, master );
        
        if(r == NULL)
        { char newline[2];
            newline[1]='\0';
            newline[0]='\n';
            for(j = 0; j < fdmax+1; j++)
            {//printf("%s",cl_list1);
                send_to_all(j, i, sockfd, strlen(cl_list1), cl_list1, master );}
        }
        
        // printf("test");
        
        
    }
	
    
}


void send_recv(int i, fd_set *master, int sockfd, int fdmax)
{
	int nbytes_recvd, j;
	char recv_buf[BUFSIZE], buf[BUFSIZE];
	
	if ((nbytes_recvd = recv(i, recv_buf, BUFSIZE, 0)) <= 0) {
		if (nbytes_recvd == 0) {
			printf("socket %d:%s hung up\n", i,getname(i));
            
            char left_indi[60]; int j;
            strcpy(left_indi,"SOC");
            left_indi[3]='\0';
            strcat(left_indi,getname(i));
            left_indi[strlen(getname(i))+3]='\0'; 
            strcat(left_indi,": Is now OFFLINE\n");
            int nbytes_recvd=strlen(left_indi);
            left_indi[nbytes_recvd]='\0';
            //printf("%s\n",left_indi);
            for(j = 0; j <= fdmax; j++)
                
                send_to_all(j, i, sockfd, nbytes_recvd, left_indi, master );
            
            delete(i);
            struct node *n;
            //display_leave(n,fdmax,j, i, sockfd, nbytes_recvd, left_indi, master);
            
            
            
		}else {
			perror("recv");
		}
		close(i);
		FD_CLR(i, master);
	}else {
int j1;
for (j1=0;j1<nbytes_recvd-1;j1++)
{mssg_type[j1]=recv_buf[j1];}
mssg_type[j1]='\0';

mssg_type1[0]=mssg_type[0];
mssg_type1[1]=mssg_type[1];
mssg_type1[2]=mssg_type[2];
mssg_type1[3]='\0';

int j2;
for (j2=0;j2<nbytes_recvd-4;j2++)
{mssg_type2[j2]=recv_buf[j2+3];}
mssg_type2[strlen(recv_buf)-3]='\0';


        //	printf("%s\n", recv_buf);
/*         printf("fdmax1:%d\n",fdmax);
		for(j = 0; j <= fdmax; j++)
             
        {send_to_all(j, i, sockfd, nbytes_recvd, recv_buf, master );}*/
        
	}
}

void connection_accept(fd_set *master, int *fdmax, int sockfd, struct sockaddr_in *client_addr,int * maxclient)
{
    // printf("Socket fd before accecpt: %d\n", sockfd);
	socklen_t addrlen;
	int newsockfd;
	
	addrlen = sizeof(struct sockaddr_in);
	if((newsockfd = accept(sockfd, (struct sockaddr *)client_addr, &addrlen)) == -1) {
		perror("accept");
		exit(1);
	}else {
		FD_SET(newsockfd, master);
		if(newsockfd > *fdmax)
        {
			*fdmax = newsockfd;
		}
		//printf("new connection from %s on port %d \n",inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));
        //printf("Socket fd after accecpt: %d\n", newsockfd);
        //JOIN
        char join_buff[BUFSIZE]; int join_bytecount;
        join_bytecount=recv(newsockfd, join_buff, BUFSIZE, 0);

        join_buff[join_bytecount] = '\0';
        //printf("Data received from Client size:%d \n data:\n %s\n",join_bytecount,join_buff);
        
        //int i,j; 
         int i= join_bytecount;int j;
        char client_name[i-3];
        for (j=3;j<=i;j++)
        { client_name[j-3]=join_buff[j];}
        
        // Check for clname repliction
        int chk= find(client_name);
        //printf("chk:%d\n",chk);
        if (chk>=1)
        { 
         char name_error[]={"Client name already exits,Please Re-enter with different name"};
		 int err_len = strlen(name_error);
		 char name_error1[err_len+3];
		  strcpy(name_error1,"SNE");name_error1[3]='\0';
		  strcat(name_error1,name_error);
		  name_error1[strlen(name_error)+3]='\0';
          printf("%s\n",name_error1);
           send(newsockfd,name_error1,err_len,0);
            FD_CLR(newsockfd, master);
            close(newsockfd);
          
            goto stop;
            
        }
        
        // Check for max number of client
        if(count()> (*maxclient)-1)
        {
            //int chk= find(client_name);
            char clientcount_error[]={"Error: Server overload, MAX Clients reached on Server"};
            int err_len = strlen(clientcount_error);
            send(newsockfd,clientcount_error,err_len,0);
            delete(newsockfd);
            FD_CLR(newsockfd, master);
            close(newsockfd);
            goto stop;
        }

        if(play==1)
        { char busy[]="SB1";
          send(newsockfd,busy,strlen(busy),0);
           delete(newsockfd);
            FD_CLR(newsockfd, master);
            close(newsockfd);
            goto stop;
        }
        
        
 else{

//send(newsockfd, buff, strlen(buff), 0);
//

            printf("\n>>>%s: Joined the chat room\n",client_name);
            char join_indi[60];
            strcpy(join_indi,client_name);
            join_indi[strlen(client_name)]='\0';
            strcat(join_indi,": Is now ONLINE");
            int nbytes_recvd=strlen(join_indi);
            join_indi[nbytes_recvd]='\0';
            printf("fdmax:%d\n",*fdmax);
            for(j = 0; j <= *fdmax && j!= newsockfd; j++)
                
                send_to_all(j, i, sockfd, nbytes_recvd, join_indi, master );
            
        }
        struct node *n;
        insert(newsockfd,client_name);
        //printf("#####Clients present in chat room#####  : \n");
        display(n,newsockfd);
        //printf("################################m#####  : \n");}
        
        
    }stop:;
    
    
}



int main(int argc, char *argv[])
{
	fd_set master;
	fd_set read_fds;
	int fdmax, i,port,maxclient;
	int sockfd= 0;
	struct sockaddr_in my_addr, client_addr;
	
	FD_ZERO(&master);
	FD_ZERO(&read_fds);
    command_parse(argc, argv, &port, &maxclient);
    
    //Setting Servers IP Address start:
    
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr; // connector's address information
    socklen_t sin_size;
    int yes=1;
    char s[INET6_ADDRSTRLEN];
    int rv;
    struct sigaction sa;
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM; // this means TCP
    hints.ai_flags = AI_PASSIVE; // use my IP, bind for listen
    if(argc!= 4) {
        printf("usage: server ip port maxclient.\n");
        return 0;
    }
    
    if ((rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }  //resolution from a server name to address
    
    //This loop comes from Beej's guide to Network Programming
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1) {
            perror("server: socket");
            continue;
        }   // creat a socket
        
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
                       sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }   //  set the socket created
        
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("server: bind");
            continue;
        }   //  start bind
        
        break;
    }
    
    if (p == NULL)  {
        fprintf(stderr, "server: failed to bind\n");
        return 2;
    }
    
    freeaddrinfo(servinfo); // all done with this structure
    
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }
    
    sa.sa_handler = sigchld_handler;                      // reap all dead processes
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

printf("Enter the maxattempts per player:");
scanf("%d",&maxattempts);    
    printf("\nTCP Server Waiting for clients on port %d\n ",port);
    
    //end
    
    
    
	FD_SET(sockfd, &master);
	
	fdmax = sockfd;
srand(time(NULL));
srand(time(NULL));

    struct timeval my_value={10,0};
	struct timeval my_interval={0,0};
	struct itimerval my_timer={my_interval,my_value};
	


  while(1)
    {
		read_fds = master;
		if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1)
           {
			perror("select");
			exit(4);
		   }
		
		for (i = 0; i <= fdmax; i++)
           {
			if (FD_ISSET(i, &read_fds))
             {
				if (i == sockfd)
						{
						  connection_accept(&master, &fdmax, sockfd, &client_addr,&maxclient);                    
						}
				else { send_recv(i, &master, sockfd, fdmax);
                                    printf("fdmax1:%d\n",fdmax); int j;
                                                							   
				                if (strcmp(mssg_type1,"CPG")==0 && play==0)
				                  {    memset(mssg_type1, 0,3);memset(mssg_type, 0,23);memset(mssg_type2, 0,20);
                                      printf("mssg_type1:%s\n",mssg_type1);
                                      play=1; func_rword();
                                      char play1[]="SG1";
                                       for(j = 0; j <= fdmax; j++)
								      {send_to_all(j, i, sockfd, strlen(play1), play1, &master ); } 

									  for(j = 0; j <= fdmax; j++)
								      {send_to_all(j, i, sockfd, strlen(srword), srword, &master ); }
                                                              
                                            
                                   }
                                  

                            printf("Number of Counter:%d \n",counter);
                               if (strcmp(mssg_type1,"CAS")==0 && counter<maxattempts*3 && play==1)
                                  {counter++;
                                      memset(mssg_type1, 0,3);memset(mssg_type, 0,23);
                                      int strike = cnt_append(getname(i));                                                            

                                      if(strcmp(mssg_type2,word)==0 && strike <=3)
                                       {

                                           printf("Winner %s: Answer: %s\n",getname(i),mssg_type2);
                                            char play1[]="SWA";

                                           for(j = 0; j <= fdmax; j++)
    								      {send_to_all(j, i, sockfd, strlen(play1), play1, &master ); } 

                                           for(j = 0; j <= fdmax; j++)
    								      {send_to_all(j, i, sockfd, strlen(getname(i)), getname(i), &master ); }
                                          
                                           for(j = 0; j <= fdmax; j++)
    								      {send_to_all(j, i, sockfd, strlen(word), word, &master ); }
                                            
                                          play=0;counter=0;cnt_reset();
                                                                            
   
                                      }
                                     else
                                      { //per client response
                                        
                                          char response[]={"Wrong Answer.Strike:"};
                                          char response_end[]={"No attempts left, wait for others to respond"};
                                          //chk_counter(i);
                                          
                                          char stk[2];stk[0]='0'+strike;stk[1]='\0'; 
                                          char response1[strlen(response)+3+1];
                                           char response_end1[strlen(response_end)+3];
                                          strcpy(response1,"SRE");response1[3]='\0';
                                          strcat(response1,response);
                                          response1[strlen(response)+3]='\0';
                                          strcat(response1,stk);
                                          response1[strlen(response)+3+1]='\0';
                                          printf("Number of strikes:%d, Counter:%d \n",strike,counter); 

                                          strcpy(response_end1,"SRW");response_end1[3]='\0';
                                          strcat(response_end1,response_end);
                                          response_end1[strlen(response_end)+3]='\0';
                             
                                             if (strike<=maxattempts)
    		                                     { printf("client:%s Response:%s Reply:%s\n",getname(i),mssg_type2,response1);
    		                                         for(j = 0; j <= fdmax; j++)
    										         {send_to_all1(j, i, sockfd, strlen(response1), response1, &master ); }
    		                                     }
                                             else 
    		                                     { printf("No more attempts left\n"); 
    		                                         for(j = 0; j <= fdmax; j++)
    										         {send_to_all1(j, i, sockfd, strlen(response_end1), response_end1, &master ); }
    		                                  
    		                                     }

                                          
                                      }
                                    }   
                                  
                                     if(counter==maxattempts*3)
                                       { 

                                           printf("No Winner: Answer: %s\n",word);
                                            char play1[]="SWA";
                                            char name[]= "No Winner";

                                           for(j = 0; j <= fdmax; j++)
    								      {send_to_all(j, i, sockfd, strlen(play1), play1, &master ); } 

                                           for(j = 0; j <= fdmax; j++)
    								      {send_to_all(j, i, sockfd, strlen(name),name, &master ); }
                                          
                                           for(j = 0; j <= fdmax; j++)
    								      {send_to_all(j, i, sockfd, strlen(word), word, &master ); }
                                            play=0;counter=0;cnt_reset();
                                                                 
                                       
                                       }

                                      memset(mssg_type2, 0,20); 
                                   
                            


                    }

			}
		}
	}
	return 0;
}
