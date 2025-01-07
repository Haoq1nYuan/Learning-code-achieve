Score::Score(int n) {
	this->n=n;
	score=new float[n];
} 
Score::Score(const Score &s){
	cNum=s.cNum; cName=s.cName;
	n=s.n; max=s.max; min=s.min; num_fail=s.num_fail; average=s.average;
	score=new float[n];
	for(int i=0;i<n;i++)
		score[i]=s.score[i];
}

Score::~Score(){ delete[] score; }  
void Score::input() {
	cin>>cNum>>cName;
	for(int i=0; i<n; i++) cin>>score[i];
}    
void Score::process() {
	num_fail=0,average=0;
	max=score[0]; min=score[0]; 
	for(int i=0; i<n; i++) {
		if(max<score[i]) max=score[i];  
		if(min>score[i]) min=score[i]; 
		if(score[i]<60) num_fail++;
		average+=score[i];
	}
	average/=n;
}



