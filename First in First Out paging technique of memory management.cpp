#include <stdio.h>
#include <stdbool.h>

bool isPageInFrame(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

void displayFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf("[ ] ");
        } else {
            printf("[%d] ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    int m;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    printf("Enter the number of pages: ");
    scanf("%d", &m);

    int pages[m];
    printf("Enter the reference string (space-separated): ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &pages[i]);
    }

    int frames[n];
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
    }

    int pageFaults = 0;
    int nextFrameIndex = 0;

    printf("\nPage Replacement Process:\n");
    for (int i = 0; i < m; i++) {
        int currentPage = pages[i];

        printf("Page %d: ", currentPage);

        if (isPageInFrame(frames, n, currentPage)) {
            printf("No page fault\n");
        } else {
            frames[nextFrameIndex] = currentPage;
            nextFrameIndex = (nextFrameIndex + 1) % n;
            pageFaults++;

            printf("Page fault (Added to frame)\n");
        }

        displayFrames(frames, n);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}

