//
//  BFSceneView.m
//  Briefs
//
//  Created by Rob Rhyne on 8/18/09.
//  Copyright Digital Arch Design, 2009. See LICENSE file for details.
//


#import "BFSceneView.h"
#import "BFActor.h"
#import "BFActorView.h"
#import "BFViewUtilityParser.h"
#import "BFPresentationDispatch.h"


@implementation BFSceneView
@synthesize scene, actor_views;

- (id)initWithScene:(BFScene *)source
{
    if (self = [super initWithImage:[BFViewUtilityParser parseImageFromRepresentation:[source bg]]]) {
        self.scene = source;
        
        // enable user interaction, per documentation
        [self setUserInteractionEnabled:YES];
        
        // display actors
        NSMutableArray *subViews = [NSMutableArray arrayWithCapacity:[[self.scene actors] count]];
        for (BFActor *actor in [self.scene actors]) {
			BFActorView *view = [[BFActorView alloc] initWithActor:actor];
            [subViews addObject:view];
			
			// handle scrollable actors
			if (actor.scrollable) {
				UIScrollView *scrollView = [[UIScrollView alloc] initWithFrame:[actor size]];
				[scrollView addSubview:view];
				[scrollView setContentSize:[view image].size];
				[scrollView flashScrollIndicators];
				[self addSubview:scrollView];
			}
			
			else [self addSubview:view];
            
        }
        self.actor_views = subViews;
    }
    return self;
}



@end
