# ICDecoder

## 说明

### JUST FOR FUN
### 一气呵成，没写注释
###　有bug可以告诉我，但我也不改

## 示例

### input.txt

```
char name[]="inso";
int i,n=3;

for(i=0;i<n;i++)
{
    printf("hello world %s\n",name);
}

i=0;

while(i++<n)
{
    puts(name);
}

if(i)
{
    i--;
}
else
{
    i++;
}
```

### output.txt

```
Sentence: char name[]="inso";
	Type: char
	New Identifier: name
	Bracket2l: [
	Bracket2r: ]
	Operator: =
	Const String: "inso"
	Segment: ;
Sentence: int i,n=3;
	Type: int
	New Identifier: i
	Operator: ,
	New Identifier: n
	Operator: =
	Number: 3
	Segment: ;
'For' Block: 
	Keyword: for
	Bracket1l: (
	Sentence: i=0;
		Identifier -> int: i
		Operator: =
		Number: 0
		Segment: ;
	Sentence: i<n;
		Identifier -> int: i
		Operator: <
		Identifier -> int: n
		Segment: ;
	Sentence: i++)
		Identifier -> int: i
		Operator: ++
		Segment: )
	Block: 
		Bracket3l: {
		Sentence: printf("hello world %s\n",name);
			Function Call: printf("hello world %s\n",name)
				Function: printf
				Bracket1l: (
				Sentence: "hello world %s\n",
					Const String: "hello world %s\n"
					Segment: ,
				Sentence: name)
					Identifier -> char*: name
					Segment: )
			Segment: ;
		Bracket3r: }
Sentence: i=0;
	Identifier -> int: i
	Operator: =
	Number: 0
	Segment: ;
while Block: 
	Keyword: while
	Bracket1l: (
	Sentence: i++<n)
		Identifier -> int: i
		Operator: ++
		Operator: <
		Identifier -> int: n
		Segment: )
	Block: 
		Bracket3l: {
		Sentence: puts(name);
			Function Call: puts(name)
				Function: puts
				Bracket1l: (
				Sentence: name)
					Identifier -> char*: name
					Segment: )
			Segment: ;
		Bracket3r: }
Whole 'If' Block: 
	if Block: 
		Keyword: if
		Bracket1l: (
		Sentence: i)
			Identifier -> int: i
			Segment: )
		Block: 
			Bracket3l: {
			Sentence: i--;
				Identifier -> int: i
				Operator: --
				Segment: ;
			Bracket3r: }
	'Else' Block: 
		Keyword: else
		Block: 
			Bracket3l: {
			Sentence: i++;
				Identifier -> int: i
				Operator: ++
				Segment: ;
			Bracket3r: }
```
