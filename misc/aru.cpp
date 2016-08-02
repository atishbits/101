void node :: sort()
{
	//int count=0;
	//int count1=0;
	node *temp;
	node *curr;
	node *exchange;
	for(temp=first;temp->next!=NULL;temp=temp->next)
	{
		for(curr=first;curr->next!=NULL;curr=curr->next)
		{
			if(curr->data>curr->next->data)
			{
				exchange=curr->next;
				curr->next=curr->next->next;
				exchange->next=curr;
				curr=exchange;
			}
		}
	}
}
